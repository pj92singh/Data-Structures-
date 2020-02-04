using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp8.Exceptions
{
    /* HttpExeception class
     * will use the related Reporter class */
    public class HttpException : Exception
    {
        public string Url { get; }
        public int StatusCode { get; }
        public HttpException(string message, string url, int statusCode) : base(message)
        {
            Url = url;
            StatusCode = statusCode;
        }
    }
}
