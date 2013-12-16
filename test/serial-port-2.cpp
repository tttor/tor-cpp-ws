#include <boost/asio/serial_port.hpp>
using namespace::boost::asio;

int main()
{
	io_service io;
	serial_port port( io, "/dev/ttyACM0" );
	port.set_option( serial_port_base::baud_rate( 9600 ) );

//	unsigned char commands[4] = { 1, 128, 240, 0 };

//	// write the commands to the device

	return 0;
}
