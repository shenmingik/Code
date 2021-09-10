#define CO_BEGIN(co)              \
    void co()                \
    {                             \
        static int save_current_; \
        switch (save_current_)    \
        {                         \
        case 0:                   \
        {

#define CO_END(co) \
    Yield();       \
    }              \
    }              \
    }              \

#define ADD_CO(...) \
    void (*co_array_[])() = {__VA_ARGS__}

#define Yield()                  \
    do                           \
    {                            \
        save_current_ = __LINE__; \
        return;\
case __LINE__:;}while (0)

#define Schdule()                                        \
    for (int i = 0;; i++)                                \
    {                                                    \
        if (i >= sizeof(co_array_) / sizeof(co_array_[0])) \
            i = 0;                                       \
        co_array_[i]();\
    }

#define WaitWhile(condition)    \
    do                           \
    {                            \
        save_current_ = __LINE__; \
    case __LINE__:               \
        if (condition)           \
            return;}while(0)
    
#define WaitUntil(condition) WaitWhile(!(condition))



#define Accept(fd,addr,alen,new_fd)\
        WaitWhile((new_fd=accept(fd,addr,alen))<0 && errno==EAGAIN)

#define Recv(fd,buf,buflen,recv_len)\
        WaitWhile((recv_len=recv(fd,buf,buflen,MAG_DONYWAIT))<0 && errno == EAGAIN)