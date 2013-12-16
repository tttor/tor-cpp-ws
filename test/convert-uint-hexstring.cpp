#include <iostream>
#include <sstream>

using namespace std;
  

std::string convToString(unsigned char *data)
{
	/*
	 * using a ostringstream to convert the hash in a
	 * hex string
	 */
	std::ostringstream os;
	for(int i=0; i<16; ++i)
	{
		/*
		 * set the width to 2
		 */
		os.width(2);

		/*
		 * fill with 0
		 */
		os.fill('0');

		/*
		 * conv to hex
		 */
		os << std::hex << static_cast<unsigned int>(data[i]);
	}

	/*
	 * return as std::string
	 */
	return os.str();
}

char get_hex_from_int_lower_than_16(unsigned int i) {
  if (i < 10) {
    return char(i);
  } else {
    switch(i) {
      case 10: return 'a';
      case 11: return 'b';
      case 12: return 'c';
      case 13: return 'd';
      case 14: return 'e';
      case 15: return 'f';
    }
  }
}

//char get_1digit_hex(unsigned int dec) {
//  switch(dec) {
//    case 0: return '0';
//    case 1: return '1';  
//    case 2: return '2';  
//    case 3: return '3';  
//    case 4: return '4';  
//    case 5: return '5';    
//    case 6: return '6';  
//    case 7: return '7';
//    case 8: return '8';
//    case 9: return '9';
//    case 10: return 'a';  
//    case 11: return 'b';  
//    case 12: return 'c';  
//    case 13: return 'd';
//    case 14: return 'e';
//    case 15: return 'f';
//  }
//}

//void get_2digit_hex(unsigned int dec, char* hex) {
//  unsigned int divider;
//  unsigned int remainder;
//  
//  // Lo digit
//  divider = dec/16;
//  remainder = dec%16;
//  hex[0] = get_1digit_hex(remainder);
//  
//  // Hi digit
//  remainder = divider%16;
//  hex[1] = get_1digit_hex(remainder);
//}

void get_1digit_hex(unsigned int dec, char* hex) {
  switch (dec) {
    case 0: *hex =  '0'; break;
    case 1: *hex =  '1'; break;  
    case 2: *hex =  '2'; break;  
    case 3: *hex =  '3'; break;  
    case 4: *hex =  '4'; break;  
    case 5: *hex =  '5'; break;    
    case 6: *hex =  '6'; break;  
    case 7: *hex =  '7'; break;
    case 8: *hex =  '8'; break;
    case 9: *hex =  '9'; break;
    case 10: *hex =  'a'; break;  
    case 11: *hex =  'b'; break;  
    case 12: *hex =  'c'; break;  
    case 13: *hex =  'd'; break;
    case 14: *hex =  'e'; break;
    case 15: *hex =  'f'; break;
  }
}

void get_2digit_hex(unsigned int dec, char* hex) {
  unsigned int divider;
  unsigned int remainder;
  char c;
  
  // Lo digit
  divider = dec/16;
  remainder = dec%16;
  
  get_1digit_hex(remainder,&c);
  hex[0] = c;
  
  // Hi digit
  remainder = divider%16;
  
  get_1digit_hex(remainder,&c);
  hex[1] = c;
}

std::string convToString_2(unsigned char* data)
{
  std::string hex_str = "";
  
  for(int i=0; i<16; ++i) {
    char hex[2] = "";
    get_2digit_hex( static_cast<unsigned int>(data[i]), hex );
    
    hex_str += hex[1];
    hex_str += hex[0];
  }
  
  return hex_str;
}

int main() {
  
  unsigned char buff[16] = "";
  buff[0] = 't';
  buff[1] = 'o';
  buff[2] = 'r';
  
  
  unsigned char* buff_ptr = buff;
  
  std::string result;
  result = convToString(buff_ptr);

  cout << result << endl;
  
  // 
  cout << "convToString_2:" << endl;
  result = convToString_2(buff_ptr);
  
  cout << result << endl;
//  //
//  char hex_digit[2] = "";
//  
//  get_2digit_hex('t',hex_digit);
//  
//  string hex_str = "";
//  for(int i=1; i>=0; --i) {
//    cout << hex_digit[i] << endl;
//    hex_str += hex_digit[i];
//  }
//  cout << hex_str << endl;
//  
  return 0;
}
