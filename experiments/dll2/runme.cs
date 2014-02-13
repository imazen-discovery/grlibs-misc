using System;
using System.Runtime.InteropServices;

public class runme
{
  [DllImport("wrap.dll", EntryPoint="wrap_gdMajorVersion")]
  public static extern int gdMajorVersion();

  static void Main() 
  {
    // Call our gcd() function

    Console.WriteLine("The version string is '" + gdMajorVersion() + "'");
  }
}
