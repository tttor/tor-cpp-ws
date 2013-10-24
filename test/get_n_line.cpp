#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

unsigned int FileRead( istream & is, vector <char> & buff ) {
    is.read( &buff[0], buff.size() );
    return is.gcount();
}

unsigned int CountLines( const vector <char> & buff, int sz ) {
    int newlines = 0;
    const char * p = &buff[0];
    for ( int i = 0; i < sz; i++ ) {
    	if ( p[i] == '\n' ) {
    		newlines++;
    	}
    }
    return newlines;
}

size_t
get_n_lines(const std::string& path)
{
  const int SZ = 1024 * 1024;
  std::vector <char> buff( SZ );
  
  ifstream ifs(path.c_str());
  size_t n = 0;
  
  ifs.read( &buff[0], buff.size() );
  int sz = ifs.gcount();
  
  const char* p = &buff[0];
  for(int i = 0; i < sz; i++ ) 
  {
    if ( p[i] == '\n' ) n++;
  }
  
  return n;
}

int main( int argc, char * argv[] ) {
    time_t now = time(0);
//    if ( argc == 1  ) {
//    	cout << "lines\n";
//    	ifstream ifs( "lines.dat" );
//    	int n = 0;
//    	string s;
//    	while( getline( ifs, s ) ) {
//    		n++;
//    	}
//    	cout << n << endl;
//    }
//    else {
    	cout << "buffer\n";
    	const int SZ = 1024 * 1024;
    	std::vector <char> buff( SZ );
    	ifstream ifs( "lines.dat" );
    	int n = 0;
    	
//    	while( int cc = FileRead( ifs, buff ) ) {
//    		n += CountLines( buff, cc );
//    	}
    	
//    	int cc = FileRead( ifs, buff );
//    	n += CountLines( buff, cc );
    	
    	n = get_n_lines("lines.dat");
    	
    	cout << n << endl;
//    }
//    cout << time(0) - now << endl;
}
