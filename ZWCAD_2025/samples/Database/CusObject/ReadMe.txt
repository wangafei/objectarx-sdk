Description: 
This application implements two commands called "CreateDict" and "IteratorDict" to demonstrate the use of the custom object, which can be used to record user-defined data in the dictionary of dwg.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use CusObject.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the CusObject.zrx file in the output directory.
3. Execute the "CreateDict" command, which creates a custom dictionary called "CUSTOM_DICT" in NamedObjectsDictionary of dwg and adds two entries(with custom data "1.11" and "2.22") to the custom dictionary.
4. Execute the "IteratorDict" command, which queries the custom datas stored in custom dictionary and print them in the command line.