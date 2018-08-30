#pragma once
namespace eastl
{
    template< typename T, unsigned int A > class DequeIterator
    {
    public:
        T*                        mpCurrent;                    //0000
        T*                        mpBegin;                    //0004
        T*                        mpEnd;                        //0008
        T**                        mpCurrentArrayPtr;            //000C

        DequeIterator<T,A> operator ++ ()
        {
            ++mpCurrent;

            if( mpCurrent == mpEnd )
            {
                ++mpCurrentArrayPtr;

                mpBegin = *mpCurrentArrayPtr;
                mpEnd = *mpCurrentArrayPtr + A;
                mpCurrent = mpBegin;
            }

            return (*this);
        }
    }; //sizeof() == 0x10

    template< typename T, unsigned int A > class DequeBase
    {
    public:
        T**                        mpPtrArray;                    //0000
        int                        mnPtrArraySize;                //0004
        DequeIterator< T, A >    mItBegin;                    //0008
        DequeIterator< T, A >    mItEnd;                        //0018
        unsigned char            pad[4];                        //0028
    }; //sizeof() == 0x2C


    template< typename T, unsigned int A > class deque : public DequeBase< T, A >
    {
    public:

        T* operator [] ( unsigned int n )
        {
            unsigned int m = n + mItBegin.mpCurrent - mItBegin.mpBegin;
            unsigned int i = ( ( signed int )( m + 0x1000000 ) ) / A - ( sizeof( T ) * 0x10000 );
            unsigned int b = m - A * ( ( signed int )( m + 0x1000000 ) ) / A - ( sizeof( T ) * 0x10000 );

            return &this->mItBegin.mpCurrentArrayPtr[i][b];
        }

        bool empty()
        {
            return this->mItBegin.mpCurrent == this->mItEnd.mpCurrent;
        }

        void begin( eastl::DequeIterator< T, A >* result )
        {
            result->mpCurrent = mItBegin.mpCurrent;
            result->mpBegin = mItBegin.mpBegin;
            result->mpEnd = mItBegin.mpEnd;
            result->mpCurrentArrayPtr = mItBegin.mpCurrentArrayPtr;
        }

        void end( eastl::DequeIterator< T, A >* result )
        {
            result->mpCurrent = mItEnd.mpCurrent;
            result->mpBegin = mItEnd.mpBegin;
            result->mpEnd = mItEnd.mpEnd;
            result->mpCurrentArrayPtr = mItEnd.mpCurrentArrayPtr;
        }

        unsigned int size()
        {
            return 
                mItEnd.mpCurrent -
                mItEnd.mpBegin +
                ( ( mItEnd.mpCurrentArrayPtr - mItBegin.mpCurrentArrayPtr ) << 6 ) +
                mItBegin.mpEnd -
                mItBegin.mpCurrent -
                A;
        }

        T* front()
        {
            return mItBegin.mpCurrent;
        }

        void clear()
        {
            if( mItBegin.mpCurrentArrayPtr != mItEnd.mpCurrentArrayPtr && mItEnd.mpBegin )
            {
                delete[] mItEnd.mpBegin;
            }

            for( T** i = ( T** )( mItBegin.mpCurrentArrayPtr + 1 );  i < mItEnd.mpCurrentArrayPtr; ++i )
            {
                if( *i )
                {
                    delete[] *i;
                }
            }

            mItEnd.mpCurrent = mItBegin.mpCurrent;
            mItEnd.mpBegin = mItBegin.mpBegin;
            mItEnd.mpEnd = mItBegin.mpEnd;
            mItEnd.mpCurrentArrayPtr = mItBegin.mpCurrentArrayPtr;
        }
    }; //sizeof() == 0x2C
};