/* Author: YiJia Chen */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Point.hpp"

namespace YiJia
{
    namespace Containers
    {
        class Array
        {
        private:
            CAD::Point* m_data;
            int m_size;

        public:
            Array();
            Array(int size);
            Array(const Array&);
            ~Array();
            const Array& operator=(const Array&);
            
            int Size() const;
            void SetElement(int index, const CAD::Point& p);
            CAD::Point& GetElement(int index) const;
            /* return element by reference since the returned element has a
            longer lifetime than the GetElement() function. */
            
            // Point& operator[](int index);
            const CAD::Point& operator[](int index);
        };

        inline int Array::Size() const
        {
            return m_size;
        };
    }
}

#endif