/*

https://www.geeksforgeeks.org/maximum-cpu-load-from-the-given-list-of-jobs/

Given an array of jobs with different time requirements, where each job consists
of start time, end time and CPU load.

The task is to find the maximum CPU load at any time if all jobs are running on
the same machine.

Examples:


Input: jobs[] = {{1, 4, 3}, {2, 5, 4}, {7, 9, 6}}
Output: 7
Explanation:
In the above-given jobs, there are two jobs which overlaps.
That is, Job [1, 4, 3] and [2, 5, 4] overlaps for the time period in [2, 4]
Hence, the maximum CPU Load at this instant will be maximum (3 + 4 = 7).


Input: jobs[] = {{6, 7, 10}, {2, 4, 11}, {8, 12, 15}}
Output: 15
Explanation:
Since, There are no jobs that overlaps.
Maximum CPU Load will be – max(10, 11, 15) = 15


This problem is generally the application of the Merge Intervals.
Approach: The idea is to maintain min-heap for the jobs on the basis of their
end times. Then, for each instance find the jobs which are complete and remove
them from the Min-heap. That is, Check that the end-time of the jobs in the
min-heap had ended before the start time of the currentLoad=0;

priority_queue<Job, vector<Job>,> job. Also at each
instance, find the maximum CPU Load on the machine by taking the sum of all the
jobs that are present in the min-heap.

For Example:

Given Jobs be {{1, 4, 3}, {2, 5, 4}, {7, 9, 6}}
Min-Heap - {}

Instance 1:
The job {1, 4, 3} is inserted into the min-heap
Min-Heap - {{1, 4, 3}},
Total CPU Load  = 3

Instance 2:
The job {2, 5, 4} is inserted into the min-heap.
While the job {1, 4, 3} is still in the CPU,
because end-time of Job 1 is greater than
the start time of the new job {2, 5, 4}.
Min-Heap - {{1, 4, 3}, {2, 5, 4}}
Total CPU Load = 4 + 3 = 7

Instance 3:
The job {7, 9, 6} is inserted into the min-heap.
After popping up all the other jobs because their
end time is less than the start time of the new job
Min Heap - {7, 9, 6}
Total CPU Load =  6

Maximum CPU Load = max(3, 7, 6) = 7
Below is the implementation of the above approach:




// C++ implementation to find the
// maximum CPU Load from the given
// lists of the jobs

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Blueprint of the job
class Job {
public:
    int start = 0;
    int end = 0;
    int cpuLoad = 0;

    // Constructor function for
    // the CPU Job
    Job(int start, int end, int cpuLoad)
    {
        this->start = start;
        this->end = end;
        this->cpuLoad = cpuLoad;
    }
};

class MaximumCPULoad {

    // Structure to compare two
    // CPU Jobs by their end time
public:
    struct endCompare {
        bool operator()(const Job& x, const Job& y)
        {
            return x.end > y.end;
        }
    };

    // Function to find the maximum
    // CPU Load at any instance of
    // the time for given jobs
    static int findMaxCPULoad(vector<Job>& jobs)
    {
        // Condition when there are
        // no jobs then CPU Load is 0
        if (jobs.empty()) {
            return 0;
        }

        // Sorting all the jobs
        // by their start time
        sort(jobs.begin(), jobs.end(),
             [](const Job& a, const Job& b) {
                 return a.start < b.start;
             });

        int maxCPULoad = 0;
        int currentCPULoad = 0;

        // Min-heap implemented using the
        // help of the priority queue
        priority_queue<Job, vector<Job>, endCompare>
            minHeap;

        // Loop to iterate over all the
        // jobs from the given list
        for (auto job : jobs) {

            // Loop to remove all jobs from
            // the heap which is ended
            while (!minHeap.empty()
                   && job.start > minHeap.top().end) {
                currentCPULoad -= minHeap.top().cpuLoad;
                minHeap.pop();
            }

            // Add the currentLoad=0;

            priority_queue<Job, vector<Job>,> Job to CPU
            minHeap.push(job);
            currentCPULoad += job.cpuLoad;
            maxCPULoad = max(maxCPULoad, currentCPULoad);
        }
        return maxCPULoad;
    }
};

// Driver Code
int main(int argc, char* argv[])
{
    vector<Job> input
        = { { 1, 4, 3 }, { 7, 9, 6 }, { 2, 5, 4 } };
    cout << "Maximum CPU load at any time: "
         << MaximumCPULoad::findMaxCPULoad(input) << endl;
}
Output
Maximum CPU load at any time: 7
Performance Analysis:

Time complexity: O(N*logN)
Auxiliary Space: O(N)
Approach 2:

The idea is simple. We have supposed n intervals, so we have 2n endpoints ( here
endpoint is the end of an interval and its value is the time associated with
it). We can take an endpoint and combine it with its load value associated with
it and with a flag which states whether it is a starting point or ending point
of an interval. Then we can just sort the endpoints in increasing order(if there
is a tie in value of endpoints then we will break the tie by putting the
endpoint which is starting at first place as compared to the endpoint which is
ending; if both the endpoints are starting or ending then we will break the tie
arbitrarily).

After sorting, we will proceed through the endpoints using for loop. And if we
have an endpoint that is the starting point of an interval then we will add the
load value associated with it in a variable say, count. We will also take the
maximum of the count values and store it in a variable called result.

But when we get an endpoint that is ending then we will decrease the load value
associated with it from the count.

At the end, we will return the result.

Lets take an example: suppose the jobs are {1, 4, 3}, {2, 5, 4}, {7, 9, 6}.

our sorted endpoints will be 1(start), 2(start), 4(end), 5(end), 7(start),
9(end) .

and the corresponding loads will be 3, 4, 3, 4, 6, 6.

start traversing the endpoints:

so after traversing first endpoint which is 1(start) we have count+=3 (here 3 is
the load associated with it) so count =3. Since the 1 is starting point so we
will update the result. So result=max(result,count) so, result=3.

After traversing 2(start) we have count+=4, so count=7,
result=max(result,count)=7.

After traversing 4(end) we have count-=3(we have subtracted because it is ending
point) so count=4. result will not be updated since we are decreasing the count.

After traversing 5(end) we have count-=4 so count=0.

After traversing 7(start) we have count+=6 so count=6,
result=max(result,count)=7.

After traversing 9(end) we have count-=6 so count=0.

Our result will be 7.




// C++ implementation to find the
// maximum CPU Load from the given array of jobs

#include <bits/stdc++.h>
using namespace std;

// the job struct will have s(starting time) , e(ending time) , load(cpu load)
struct Job {
    int s, e, load;
};

// endpoint struct will have val(the time associated with the endpoint),
// load(cpu load associated with the endpoint),
// a flag isStart which will tell if the endpoint is starting or ending point of
// an interval
struct Endpoint {
    int val, load;
    bool isStart;
};

// custom comparator function which is used by the c++ sort stl
bool comp(const Endpoint& a, const Endpoint& b) {
    if (a.val != b.val)
        return a.val < b.val;
    return a.isStart == true && b.isStart == false;
}
//function to find maximum cpu load
int maxCpuLoad(vector<Job> v)
{
    int count = 0; // count will contain the count of currentLoad=0;

    priority_queue<Job, vector<Job>,> loads
      int result = 0; // result will contain maximum of all counts

      // this data array will contain all the endpoints combined with their load
values
      // and flags telling whether they are starting or ending point
    vector<Endpoint> data;

    for (int i = 0; i < v.size(); i++) {
        data.emplace_back(Endpoint{ v[i].s, v[i].load, true});
        data.emplace_back(Endpoint{ v[i].e, v[i].load, false});
    }

    sort(data.begin(), data.end(), comp);

    for (int i = 0; i < data.size(); i++) {
        if (data[i].isStart == true) {
            count += data[i].load;
            result = max(result, count);
        }
        else
            count -= data[i].load;

    }

    return result;
}
//Driver code to test maxCpuLoad function
int main() {
    vector<Job> v = {
        {6, 7, 10},
          {2, 4, 11},
          {8, 12, 15}
    };
    cout << maxCpuLoad(v);
    return 0;
}
// this code is contributed by Mohit Puri
Output
15
Time Complexity: O(nlogn) for sorting the data array.
Auxiliary Space: O(n) which is the size of the data array


*/

#include <bits/stdc++.h>
using namespace std;

class Job {
public:
  int start;
  int end;
  int cpuLoad;
  Job(int st, int en, int load) : start{st}, end{en}, cpuLoad{load} {}
  void printjob() {
    cout << "{" << start << ", " << end << ", " << cpuLoad << "}" << endl;
  }
};

class MaximumCPULoad {
public:
  static int findMaxCPULoad(vector<Job> &jobs) {
    if (jobs.empty())
      return 0;
    sort(jobs.begin(), jobs.end(), [](const Job &left, const Job &right) {
      return left.start < right.start;
    });

    int maxCPULoad = 0;
    int currentLoad = 0;
    auto endCompare = [](const Job &left, const Job &right) {
      return left.end > right.end;
    };
    priority_queue<Job, vector<Job>, decltype(endCompare)> minHeap(endCompare);
    // minHeap.push(jobs[0]);
    // currentLoad = currentLoad + job.cpuLoad;
    // maxCPULoad = max(maxCPULoad, currentLoad);

    for (auto &job : jobs) {

      while (!minHeap.empty() && job.start > minHeap.top().end) {
        currentLoad = currentLoad - minHeap.top().cpuLoad;
        minHeap.pop();
      }

      minHeap.push(job);
      currentLoad = currentLoad + job.cpuLoad;
      maxCPULoad = max(maxCPULoad, currentLoad);
    }
    return maxCPULoad;
  }
};

/*
Approach 2:

The idea is simple. We have supposed n intervals, so we have 2n endpoints ( here
endpoint is the end of an interval and its value is the time associated with
it). We can take an endpoint and combine it with its load value associated with
it and with a flag which states whether it is a starting point or ending point
of an interval. Then we can just sort the endpoints in increasing order(if there
is a tie in value of endpoints then we will break the tie by putting the
endpoint which is starting at first place as compared to the endpoint which is
ending; if both the endpoints are starting or ending then we will break the tie
arbitrarily).

After sorting, we will proceed through the endpoints using for loop. And if we
have an endpoint that is the starting point of an interval then we will add the
load value associated with it in a variable say, count. We will also take the
maximum of the count values and store it in a variable called result.

But when we get an endpoint that is ending then we will decrease the load value
associated with it from the count.

At the end, we will return the result.

Lets take an example: suppose the jobs are {1, 4, 3}, {2, 5, 4}, {7, 9, 6}.

our sorted endpoints will be 1(start), 2(start), 4(end), 5(end), 7(start),
9(end) .

and the corresponding loads will be 3, 4, 3, 4, 6, 6.

start traversing the endpoints:

so after traversing first endpoint which is 1(start) we have count+=3 (here 3 is
the load associated with it) so count =3. Since the 1 is starting point so we
will update the result. So result=max(result,count) so, result=3.

After traversing 2(start) we have count+=4, so count=7,
result=max(result,count)=7.

After traversing 4(end) we have count-=3(we have subtracted because it is ending
point) so count=4. result will not be updated since we are decreasing the count.

After traversing 5(end) we have count-=4 so count=0.

After traversing 7(start) we have count+=6 so count=6,
result=max(result,count)=7.

After traversing 9(end) we have count-=6 so count=0.

Our result will be 7.




// C++ implementation to find the
// maximum CPU Load from the given array of jobs

#include <bits/stdc++.h>
using namespace std;

// the job struct will have s(starting time) , e(ending time) , load(cpu load)
struct Job {
    int s, e, load;
};

// endpoint struct will have val(the time associated with the endpoint),
// load(cpu load associated with the endpoint),
// a flag isStart which will tell if the endpoint is starting or ending point of
// an interval
struct Endpoint {
    int val, load;
    bool isStart;
};

// custom comparator function which is used by the c++ sort stl
bool comp(const Endpoint& a, const Endpoint& b) {
    if (a.val != b.val)
        return a.val < b.val;
    return a.isStart == true && b.isStart == false;
}
//function to find maximum cpu load
int maxCpuLoad(vector<Job> v)
{
    int count = 0; // count will contain the count of current loads
      int result = 0; // result will contain maximum of all counts

      // this data array will contain all the endpoints combined with their load
values
      // and flags telling whether they are starting or ending point
    vector<Endpoint> data;

    for (int i = 0; i < v.size(); i++) {
        data.emplace_back(Endpoint{ v[i].s, v[i].load, true});
        data.emplace_back(Endpoint{ v[i].e, v[i].load, false});
    }

    sort(data.begin(), data.end(), comp);

    for (int i = 0; i < data.size(); i++) {
        if (data[i].isStart == true) {
            count += data[i].load;
            result = max(result, count);
        }
        else
            count -= data[i].load;

    }

    return result;
}
//Driver code to test maxCpuLoad function
int main() {
    vector<Job> v = {
        {6, 7, 10},
          {2, 4, 11},
          {8, 12, 15}
    };
    cout << maxCpuLoad(v);
    return 0;
}
// this code is contributed by Mohit Puri
Output
15
Time Complexity: O(nlogn) for sorting the data array.
Auxiliary Space: O(n) which is the size of the data array

*/
class EndPoint {
public:
  int val;
  int load;
  bool isStart;
  EndPoint(int v, int lod, bool st) : val{v}, load{lod}, isStart{st} {}
};

bool mycompare(const EndPoint &left, const EndPoint &right) {
  if (left.val != right.val) {
    return left.val < right.val;
  }
  return left.isStart == true && right.isStart == false;
}

int maxCpuLoad_approach2(vector<Job> &jobs) {
  int count = 0;
  int result = 0;
  vector<EndPoint> endPoints;
  for (auto &job : jobs) {
    endPoints.push_back(EndPoint(job.start, job.cpuLoad, true));
    endPoints.push_back(EndPoint(job.end, job.cpuLoad, false));
  }

  sort(endPoints.begin(), endPoints.end(), mycompare);

  for (auto &endpoint : endPoints) {
    if (endpoint.isStart) {
      count += endpoint.load;
      result = max(result, count);
    } else {
      count = count - endpoint.load;
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {

  vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}}; // {1, 10, 100},

  //   auto endCompare = [](const Job &left, const Job &right) {
  //     return left.end > right.end;
  //   };
  //   priority_queue<Job, vector<Job>, decltype(endCompare)>
  //   minHeap(endCompare);

  //   for (auto &i : input) {
  //     minHeap.push(i);
  //   }

  //   while (!minHeap.empty()) {
  //     auto topp = minHeap.top();
  //     topp.printjob();
  //     minHeap.pop();
  //   }
#ifdef METHOD
  MaximumCPULoad mcl;
  cout << "\n max CPU LOAD (using Method of PQ minHeap)= "
       << (mcl.findMaxCPULoad(input)) << endl;
#else
  cout << "\n max CPU LOAD (Using Endpoint structure) = "
       << (maxCpuLoad_approach2(input)) << endl;

#endif // !METHOD

  //   cout << "\n max CPU LOAD = " << (maxCpuLoad_approach2(input)) << endl;

  return 0;
}
