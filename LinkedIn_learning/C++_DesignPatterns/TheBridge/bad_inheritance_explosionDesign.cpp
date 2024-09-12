#include <bits/stdc++.h>
using namespace std;

class ITextShare {
public:
  virtual bool shareText(const string &text) = 0;
  virtual ~ITextShare() = default;
};

class EmailShare : public ITextShare {
public:
  virtual bool shareText(const string &text) {
    cout << "EmailShare::shareText(). sharing text = " << text << endl;
    return true;
  }
};

class SMSShare : public ITextShare {
public:
  virtual bool shareText(const string &text) {
    cout << "SMSShare::shareText(). sharing text = " << text << endl;
    return true;
  }
};

// some one asked for encryptionenabled msgiing fo bad design approach

class SecureEmailShare : public EmailShare {
private:
  string xorEncrypt(const string &input) {
    char key = 64;
    string output = input;
    for (auto &i : output) {
      i = i ^ key;
    }
    return output;
  }

public:
  virtual bool shareText(const string &text) {
    cout << "SecureEmailShare::shareText(). sharing text = "
         << (xorEncrypt(text)) << endl;
    return true;
  }
};

class SecureSMSShare : public SMSShare {
private:
  string xorEncrypt(const string &input) {
    char key = 64;
    string output = input;
    for (auto &i : output) {
      i = i ^ key;
    }
    return output;
  }

public:
  virtual bool shareText(const string &text) {
    cout << "SecureSMSShare::shareText(). sharing text = " << (xorEncrypt(text))
         << endl;
    return true;
  }
};

int main(int argc, char const *argv[]) {
  // clang-format off
    const unique_ptr<ITextShare> shareServices []
    {
        make_unique<EmailShare>(),
        make_unique<SMSShare>(),
        make_unique<SecureEmailShare>(),
        make_unique<SecureSMSShare>()
    };
  // clang-format on
  const string content = "Hi faraz Alam";
  for (auto &services : shareServices) {
    services->shareText(content);
    cout << endl;
  }

  return 0;
}

#if 0
class ITextShare {
public:
  virtual bool shareText(const string &text) = 0;
  virtual ~ITextShare() = default;
};

class EmailShare : public ITextShare {
public:
  bool shareText(const string &text) override {
    cout << "EmailShare::shareText() sharing text: " << text << endl;
    return true;
  }
};

class SMSShare : public ITextShare {
public:
  bool shareText(const string &text) override {
    cout << "SMSShare::shareText() sharing text: " << text << endl;
    return true;
  }
};

class EmailShareEncrypted : public EmailShare {
public:
  bool shareText(const string &text) override {
    cout << "EmailShareEncrypted::shareText() encrypting text..." << endl;
    string encrypted = xorEncrypt(text);
    return EmailShare::shareText(encrypted);
  }

private:
  string xorEncrypt(const string &input) {
    char key = 64;
    string output = input;

    for (int i = 0; i < input.size(); ++i)
      output[i] = input[i] ^ key;

    return output;
  }
};

class SMSShareEncrypted : public SMSShare {
public:
  bool shareText(const string &text) override {
    cout << "SMSShareEncrypted::shareText() encrypting text..." << endl;
    string encrypted = xorEncrypt(text);
    return SMSShare::shareText(encrypted);
  }

private:
  string xorEncrypt(const string input) {
    char key = 64;
    string output = input;

    for (int i = 0; i < input.size(); ++i)
      output[i] = input[i] ^ key;

    return output;
  }
};

class EmailShareAutoExpiring : public EmailShare {
  //...
};

class SMSShareAutoExpiring : public SMSShare {
  //...
};

int main() {
  // Create an array of pointers to CloudStorage objects.
  const std::unique_ptr<ITextShare> sharingServices[]{
      make_unique<EmailShare>(), make_unique<SMSShare>(),
      make_unique<EmailShareEncrypted>(), make_unique<SMSShareEncrypted>()};

  // Iterate through the array and invoke the uploadContents and getFreeSpace
  // methods on each object
  const string content = "Beam me up, Scotty!";
  for (const auto &service : sharingServices) {
    service->shareText(content);
    cout << endl;
  }

  return 0;
}

#endif