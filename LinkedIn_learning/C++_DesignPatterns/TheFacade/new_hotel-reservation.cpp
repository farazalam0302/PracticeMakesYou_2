#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Mock class for database library
class Database {
public:
  void storeReservation(const string &reservation) {
    cout << "Database: Storing reservation: " << reservation << endl;
  }
};

// Mock class for payment gateway
class PaymentGateway {
public:
  void processPayment(const string &paymentInfo) {
    cout << "Payment Gateway: Processing payment with info: " << paymentInfo
         << endl;
  }
};

// Mock class for messaging service
class MessagingService {
public:
  void sendConfirmation(const string &message) {
    cout << "Messaging Service: Sending confirmation message: " << message
         << endl;
  }
};

class ReservationSystemFacade {
private:
  Database m_Database;
  PaymentGateway m_paymentGateway;
  MessagingService m_messagingService;

public:
  ReservationSystemFacade()
      : m_Database(), m_paymentGateway(), m_messagingService() {}
  void makereservation(const string &reservationInfo,
                       const string &paymentinfo) {
    m_Database.storeReservation(reservationInfo);
    m_paymentGateway.processPayment(paymentinfo);
    m_messagingService.sendConfirmation("Reservation Confirmed....");
  }
};

int main() {
  //   Database db;
  //   PaymentGateway paymentGateway;
  //   MessagingService messagingService;

  const string reservation = "Room reservation info";
  //   db.storeReservation(reservation);

  const string paymentInfo = "Payment info";
  //   paymentGateway.processPayment(paymentInfo);

  //   messagingService.sendConfirmation("Reservation confirmed.");

  ReservationSystemFacade reservationSystem;
  reservationSystem.makereservation(reservation, paymentInfo);

  return 0;
}
