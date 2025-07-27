using System;
using System.Diagnostics;
using System.IO;
using System.Reflection;

namespace EnvPathSetter
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string sdkDir = @"D:\Autodesk\ObjectARXSDK\"; //环境变量路径,以 \结尾
            string strEnvName = String.Empty; //环境变量名称


            //获得当前程序的路径
            string path = Assembly.GetExecutingAssembly().Location;
            sdkDir = Path.GetDirectoryName(path);

            Debug.Assert(sdkDir != null, nameof(sdkDir) + " != null");
            if (!sdkDir.EndsWith("\\"))
            {
                sdkDir += "\\";
            }


            //从路径中获得文件名(不含后缀)
            string fileName = Path.GetFileNameWithoutExtension(path);

            //判断路径中是否包含-字符
            //自动处理
            if (fileName.Contains("-"))
            {
                //将字符串按-分割成数组
                string[] strArray = fileName.Split('-');

                //获得数组的最后一个元素
                strEnvName = strArray[strArray.Length - 1];

                Console.WriteLine("功能说明:即将当前路径设为SystemVariable.");
                Console.WriteLine($"根据exe解析得到的变量名为:{strEnvName}");
                Console.WriteLine($"按任意键继续...");
                ConsoleKeyInfo strInput = Console.ReadKey();
            }
            else //手动处理
            {
                Console.WriteLine("功能说明:将当前路径设为SystemVariable, 请输入变量名:\n");
                Console.WriteLine("如: FsArxSdkDir 或 FsToolsDir");
                try
                {
                    string strInput = Console.ReadLine();
                    if (!string.IsNullOrEmpty(strInput))
                    {
                        strEnvName = strInput.Trim();
                    }
                    else
                    {
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    Console.ReadKey();
                }
            }


            try
            {
                if (!string.IsNullOrEmpty(strEnvName))
                {
                    Console.WriteLine("执行中...");
                    Environment.SetEnvironmentVariable(strEnvName, sdkDir, EnvironmentVariableTarget.Machine);

                    // 检查User的环境变量是否存在，如果存在将其删除，避免与Machine的环境变量冲突
                    string userEnvValue = Environment.GetEnvironmentVariable(strEnvName, EnvironmentVariableTarget.User);
                    if (!string.IsNullOrEmpty(userEnvValue))
                    {
                        Environment.SetEnvironmentVariable(strEnvName, null, EnvironmentVariableTarget.User);
                        Console.WriteLine($"已清空同名的User环境变量{strEnvName},避免跟Machine冲突...");
                    }

                    Console.WriteLine($"设置环境变量{strEnvName}成功!\n按任意键退出...");
                    Console.ReadKey();
                }
            }
            catch (Exception e)
            {
                Debug.Assert(false);
                Console.WriteLine(e);
                throw;
            }
        }
    }
}