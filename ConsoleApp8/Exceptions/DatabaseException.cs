using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp8.Exceptions
{
	/* 
	*example exception class 1 for DB (2 more will be created for 
	* http and files)
	* uses a public method for throwing database related exeception
	* will be used in the main program along with the reporter interface
	*/
    public class DatabaseException : Exception
    {
        public string DbName { get; }

        public DatabaseException(string message, string dbName) : base(message)
        {
            DbName = dbName; 
        }
    }
}
