filename="listoffiles.sh"
array=[]
queue=[]
stack=[]
with open (filename,"r+") as f:
	for line in f:
		if "array" in line:
			array.append(line)
		elif "queue" in line:
			queue.append(line)
		elif "stack" in line:
			stack.append(line)
		else:
			pass;

for i in array:
	print i