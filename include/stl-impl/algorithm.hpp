#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace kxf::stl
{
    template<typename InIter, class Pred>
    constexpr Pred for_each(InIter begin, InIter end, Pred pred)
    {
        for (; begin != end; ++begin)
            pred(*begin);

        return pred;
    }

    template<typename InIter, typename Size, class Pred>
    constexpr Pred for_each_n(InIter begin, Size n, Pred pred)
    {
        for (Size i = 0; i < n; ++i)
            pred(*begin++);

        return pred;
    }

    template<typename InIter, typename Pred>
    constexpr bool all_of(InIter begin, InIter end, Pred pred)
    {
        for (; begin != end; ++begin)
            if (!pred(*begin))
                return false;

        return true;
    }

    template<typename InIter, typename Pred>
    constexpr bool any_of(InIter begin, InIter end, Pred pred)
    {
        for (; begin != end; ++begin)
            if (pred(*begin))
                return true;

        return false;
    }

    template<typename InIter, typename Pred>
    constexpr bool none_of(InIter begin, InIter end, Pred pred)
    {
        for (; begin != end; ++begin)
            if (pred(*begin))
                return false;

        return true;
    }

    template<typename InIter, typename T>
    constexpr InIter find(InIter begin, InIter end, const T& value)
    {
        for (; begin != end; ++begin)
            if (*begin == value)
                return begin;

        return end;
    }

    template<typename InIter, typename Pred>
    constexpr InIter find_if(InIter begin, InIter end, Pred pred)
    {
        for (; begin != end; ++begin)
            if (pred(*begin))
                return begin;

        return end;
    }

    template<typename InIter, typename Pred>
    constexpr InIter find_if_not(InIter begin, InIter end, Pred pred)
    {
        for (; begin != end; ++begin)
            if (!pred(*begin))
                return begin;

        return end;
    }
}

#endif //ALGORITHM_H
