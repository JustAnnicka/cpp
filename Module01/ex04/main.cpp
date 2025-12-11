#include <iostream> 
#include <string>
#include <fstream>

std::string	ft_replace_strings(std::string text, std::string s1, std::string s2)
{
	std::string	new_text;
	size_t found = text.find(s1);
	size_t new_pos = 0;
	
 	while (found!=std::string::npos)
	{ 		
		new_text += text.substr(new_pos, found - new_pos);
		new_text += s2;
		new_pos = found;
		text.erase(found, s1.length());
		found = text.find(s1);
	}
	return (new_text);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error\nFormat: filename s1 s2" << std::endl;
		(void)argv;
		return (1);
	}
	std::string	out = argv[1];
	out += ".replace";
	const char *output = out.c_str();
	std::ifstream file (argv[1]);
	if(file.fail())
		return (std::cout << "Error opening file") << std::endl, 1;
	std::ofstream outfile (output ,std::ofstream::binary);
	if (file.is_open()) 
	{
		//get size of file
		file.seekg (0,file.end);
		long size = file.tellg();
		file.seekg (0);
		char* buffer = new char[size];
		file.read (buffer,size);
		std::string text = buffer;
		text = ft_replace_strings(text, argv[2], argv[3]);
		delete[] buffer;
		buffer = (char *)text.c_str();
		// write to outfile
		outfile.write (buffer,text.length());
		file.close();
		outfile.close();
	}
	return (0);
}
