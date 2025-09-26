/* Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You must create and turn in your
own tests to ensure that your program works as expected. */

#include <iostream> 
#include <string>
#include <fstream>

std::string	ft_replace_strings(std::string text, std::string s1, std::string s2)
{

	std::cout << text << std::endl;
	size_t found = text.find(s1);
 	while (found!=std::string::npos)
	{ 		
	//	std::cout << "found pos: " << found << std::endl;
		text.erase(found, s1.length());
		text.insert(found, s2);
		found = text.find(s1);
	//	std::cout << "new text: " << text << std::endl;
	}
	return (text);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error\nFormat: filename s1 s2";
		(void)argv;
		return (1);
	}
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	out = argv[1];
	out += ".replace";
	//std::cout << out;
	const char *output = out.c_str();
	std::ifstream file (argv[1]);
	std::ofstream outfile (output ,std::ofstream::binary);
	if (file.is_open()) 
	{
		file.seekg (0,file.end);
		// I think this is wrong buffer size should be of original file
		// The calc for the size should occur at the end once i know the number of occurances
		//long size = s1.length() - s2.length() + 1;
		long size = file.tellg();
		file.seekg (0);
		// print file:
		//char c = file.get();
		char* buffer = new char[size];

		// read content of infile
		file.read (buffer,size);
		std::string text = buffer;

	//	std::cout << buffer;
		text = ft_replace_strings(text, s1, s2);
	//	std::cout << text;
		buffer = (char *)text.c_str();
		// write to outfile
		outfile.write (buffer,text.length());
		outfile.close();
 		file.close();
		/* while (file.good()) 
		{
			std::cout << c;
			c = file.get();
		} 
	} */
		file.close();
	}
	
}

/* // get size of file
  infile.seekg (0,infile.end);
  long size = infile.tellg();
  infile.seekg (0);

  // allocate memory for file content
  char* buffer = new char[size];

  // read content of infile
  infile.read (buffer,size);

  // write to outfile
  outfile.write (buffer,size);

  // release dynamically-allocated memory
  delete[] buffer; */