//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           27.09.2021
//==============================================

namespace sdds {

   struct PhoneNumber {
      int m_number;
      int m_areacode;
   };

   struct Guest {
      char m_name[21];
      PhoneNumber m_phno;
   };

   struct GuestList {
      Guest* m_gst;
      int m_noOfGuests;
   };

   void read(char* str, int len);
   void read(PhoneNumber& thePhoneNumber);
   bool read(Guest& theGuest);
   void print(const PhoneNumber& thePhoneNumber);
   void print(const GuestList& theGuestList);
   void addGuest(GuestList& theGuestList, const Guest& aGuest);

}