
#include <bits/stdc++.h>
using namespace std;

class ITextHandler {
public:
  virtual string prepareMsg(const string &msg) const = 0; // abstract method
  virtual ~ITextHandler() = default;
};

class ITextSharer {
private:
  const ITextHandler &m_handler;

public:
  virtual ~ITextSharer() = default;
  explicit ITextSharer(const ITextHandler &handler) : m_handler(handler) {}
  bool shareMsg(const string &msg) {
    const string preparedMsg = m_handler.prepareMsg(msg);
    return sharePreparedMsg(preparedMsg);
  }

protected:
  virtual bool sharePreparedMsg(const string &msg) = 0;
};

class PlainTextHandler : public ITextHandler {
public:
  virtual string prepareMsg(const string &msg) const override {
    cout << "PlainTextHandler::prepareMsg() -> msg = \n";
    return msg;
  }
};

class EmailShare : public ITextSharer {
public:
  explicit EmailShare(const PlainTextHandler &handler) : ITextSharer(handler) {}
  virtual bool sharePreparedMsg(const string &msg) override {
    cout << "EmailShare::shareText() sharing text: " << msg << endl;
    return true;
  }
};

class EncryptedTextHandler : public ITextHandler {

public:
  string prepareMsg(const string &msg) const override {
    cout << "EncryptedTextHandler::prepareMsg() encrypted msg .. " << endl;
    return (xorEncrypt(msg));
  }

private:
  string xorEncrypt(const string &msg) const {
    char key = 60;
    string output = msg;
    for (auto &c : output) {
      c = c ^ key;
    }

    return output;
  }
};

class EncryptedEmailShare : public ITextSharer {
public:
  explicit EncryptedEmailShare(const EncryptedTextHandler &handler)
      : ITextSharer(handler) {}

protected:
  virtual bool sharePreparedMsg(const string &msg) override {
    cout << "EncryptedEmailShare::sharePreparedMsg() sharing text: " << msg
         << endl;
    return true;
  }
};

int main(int argc, char const *argv[]) {
  PlainTextHandler plainHandler = PlainTextHandler();
  EncryptedTextHandler encryptHandler = EncryptedTextHandler();
  // clang-format off
  const unique_ptr<ITextSharer> services[]
  {
    make_unique<EncryptedEmailShare>(encryptHandler),
    make_unique<EmailShare>(plainHandler)

  };

  // clang-format on
  const string msg = "ALAM Faraz";
  for (auto &i : services) {
    i->shareMsg(msg);
    cout << endl;
  }

  return 0;
}
