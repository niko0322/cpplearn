// cpplearn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Singleton
{
private:
    static Singleton* s_Instance;
    Singleton() {}
public:
    static Singleton& Get() { return *s_Instance; }
    void Hello() { std::cout << "hello" << std::endl; }
};
Singleton* Singleton::s_Instance = nullptr;

class Singleton2
{
    Singleton2() {}
public:
    static Singleton2& Get() { 
        static Singleton2 Instance;
        return Instance;
    }
    void Hello() { std::cout << "hello" << std::endl; }
};


class Log 
{
public:

    enum Level :char
    {
        LevelError = 0, LevelWarn, LevelInfo
    };
    void SetLogLevel(Level LogLevel)
    {
        m_LogLevel = LogLevel;
    }
    void Info(const char* message) 
    {
        if(m_LogLevel>= LevelInfo)
            std::cout << "[Info]:" << message << std::endl;
    }
    void Warn(const char* message) 
    {
        if (m_LogLevel >= LevelWarn)
            std::cout << "[Warn]:" << message << std::endl;
    }
    void Error(const char* message) 
    {
        if (m_LogLevel >= LevelError)
            std::cout << "[Error]:" << message << std::endl;
    }

private:
    Level m_LogLevel = LevelInfo;
};

int main()
{
    int i = 1;
    int* p = &i;
    std::cout << *p << std::endl;
    char* buf = new char[8];
    memset(buf, 0, 8);
    delete[] buf;
    buf = nullptr;

    Log log;
    log.SetLogLevel(log.LevelWarn);
    log.Error("warning");
    log.Warn("warning");
    log.Info("warning");

    //double p1 = 1, p2 = 0, p3 = 0;
    //for (int i = 0; i <= 30; i++) {
    //    p1 = 0.8 * p1 + 0.4 * p2 + 0.2 * p3;
    //    p2 = 0.2 * p1 + 0.4 * p2 + 0.6 * p3;
    //    p3 = 0 * p1 + 0.2 * p2 + 0.2 * p3;

    //    if (10 < i && i < 25)
    //        std::cout <<"count:" <<i<< " p1:" << p1 << " p2:" << p2 << " p3:" << p3 << std::endl;
    //}



    
# include"../EndBrace.h"

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
