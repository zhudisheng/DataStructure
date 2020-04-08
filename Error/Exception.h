#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

namespace ZXRLib
{
#define THROW_EXCEPTION(e,m) (throw e(m,__FILE__,__LINE__))
class Exception
{
protected:
    char* m_message;
    char* m_location;
    void init(const char* message,const char*file,int line);
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message,const char*file,int line);

    Exception(const Exception&e);
    Exception& operator= (const Exception& e);

    virtual const char* message()const;
    virtual const char* location()const;

    virtual ~Exception();
};
class ArithmetricException:public Exception
{
public:
    ArithmetricException():Exception(0){}
    ArithmetricException(const char* message):Exception(message){}
    ArithmetricException(const char*file,int line):Exception(file,line){}
    ArithmetricException(const char*message,const char*file,int line):Exception(message,file,line){}
    ArithmetricException(const ArithmetricException& e):Exception(e){}
    ArithmetricException& operator= (const ArithmetricException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};
}

#endif // EXCEPTION_H
