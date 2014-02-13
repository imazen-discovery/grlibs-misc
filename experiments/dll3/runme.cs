using System;
using System.Runtime.InteropServices;

public class runme
{
  [DllImport("wrap.dll", EntryPoint="wrap_gdMajorVersion")]
  public static extern int gdMajorVersion();

  static void Main() 
  {
    Console.WriteLine("The major version is " + gdMajorVersion());
  }
}
