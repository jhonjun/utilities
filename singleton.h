//
// singleton.h
// ~~~~~~~~~~~
// Leak-free singleton class wrapper.
//
// @author    Jhonjun Dormitorio [JJD]
// @date      2017.08.16
//

#include <memory>

template <typename T>
class singleton
{
public:
    static T* instance()
    {
        static std::unique_ptr<T> t(new T);
        return t.get();
    }

private:
    ~singleton() = default;
    singleton() = default;
    singleton(const T&) = delete;
    singleton& operator=(const T&) = delete;
};


