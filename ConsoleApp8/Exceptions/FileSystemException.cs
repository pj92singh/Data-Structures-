using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp8.Exceptions
{
	/* 
	*example exception class 2 for Filesystem and files
	* uses the a public method for throwing file system errors
	* will be used in the main program along with the reporter interface
	*/
    public class FileSystemException : Exception
    {
        public FileSystemException(string message) : base(message)
        {
        }
    }
}
