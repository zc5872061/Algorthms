#ifndef INSERTSORTE_H
#define INSERTSORTE_H


namespace SortAlgorithm 
{
    template<typename Iterator,typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type> >
    void insert_sort(const Iterator begin,const Iterator end,CompareType compare=CompareType())
    {
            //typedef typename std::iterator_traits<Iterator>::value_type T;// 迭代器指向对象的值类型
            auto size=std::distance(begin,end);
            if(size<=1)
                return;
            Iterator current=begin;
            while(++current!=end)
            {
                auto small_next=current; //指向比*current小的元素中最大的那个元素
                while(small_next!=begin && compare(*current,*(small_next-1))) //current较小，则向前寻找插入的位置插入
                {
                    small_next--;
                }

                auto key=*current;
                auto iter=current;
                while(iter!=small_next) //插入
                {
                    *iter=*(iter-1); //后移
                    iter--;
                }
                *(iter)=key;
            }
    }

    template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type> >
    void merge(const Iterator begin,const Iterator end, const Iterator middle, CompareType compare = CompareType())
    {
        typedef typename std::iterator_traits<Iterator>::value_type T;
        if(std::distance(begin,middle) <= 0 || std::distance(middle,end) <= 0)
            return;
        std::vector<T> result(begin,end);
        auto current = result.begin();
        auto left_current = begin;
        auto right_current = middle;
        while(left_current != middle && right_current != end)
        {
            if(compare(*left_current,*right_current))
            {
                *current++ = *left_current++;
            }
            else
            {
                *current++ = *right_current++;    
            }
        }

        if(left_current==middle&&right_current!=end) //当左侧序列为搬空
        {
            std::copy(right_current,end,current);
        }
        if(right_current==end&&left_current!=middle) //当右侧序列搬空
        {
            std::copy(left_current,middle,current);
        }
        std::copy(result.begin(),result.end(),begin); //复制回原序列，因此是非原地的
    }

    template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type> >
    void merge_sort(const Iterator begin, const Iterator end, CompareType compare = CompareType())
    {
        auto size = std::distance(begin, end);
        if(size > 1)
        {
            Iterator middle = begin + size/2;
            merge_sort(begin,middle,compare);
            merge_sort(middle,end,compare);
            merge(begin,end,middle,compare);
        }
    }
}

// }

#endif // INSERTSORTE_H