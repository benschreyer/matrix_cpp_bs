#ifndef _MATRIX_H__
#define _MATRIX_H__

#define MAGNITUDE_CUTOFF 0.000001

#include<string>
#include<array>
#include<iostream>
template <int R, int C,typename T>
class Matrix
{
    private:
        int rows;
        int columns;
        //std::string (*toStringFunction)(const T x);
        //float (*magnitudeFunction)(const T x);
        //Pointer to array of _rows_ pointers to each row array
        T** ptr;



    public:
        Matrix<R,C,T>(/*std::string  (*tSF)(const T), float (*magF)(const T),*/ T* r);
        Matrix<R,C,T>(/*std::string  (*tSF)(const T), float (*magF)(const T),*/);
        ~Matrix<R,C,T>();

        void setEntry(int row, int column, T data);
        T getEntry(int row, int column) const;

        //Matrix<T> operator*(const Matrix<T>& mat);
        template<int J>
        Matrix<R,J,T> operator*(const Matrix<R,J,T>& mat) const;

        Matrix<R,C,T> operator+(const Matrix<R,C,T>& mat) const;
        Matrix<R,C,T> operator*(const T& n) const;

        Matrix<R,C,T> RRef() const;

        std::string toString() const;

        //std::string (*pm)(T) getToStringFunction();





};

template <int R, int C,typename T>
Matrix<R,C,T>::~Matrix()
{
    for(int i = 0;i < this->rows;i++)
    {
        free(this->ptr[i]);
    }
    free(ptr);
}


template <int R, int C,typename T>
Matrix<R,C,T>::Matrix(/*std::string  (*tSF)(const T), float (*magF)(const T),*/ T* r)
{   
    this->rows = R;
    this->columns = C;
    this->ptr = (T**)malloc(sizeof(T*) * this->rows);



    for(int i = 0; i < this->rows; i++)
    {
        this->ptr[i] = (T*)malloc(sizeof(T) * this->columns);

        for(int j = 0; j < this->columns; j++)
        {
            this->ptr[i][j] = r[j + this->columns * i];
        }
    }
}



template <int R, int C,typename T>
Matrix<R,C,T>::Matrix(/*std::string  (*tSF)(const T), float (*magF)(const T) , */ )
{   
    
    this->rows = R;
    this->columns = C;
    this->ptr = (T**)malloc(sizeof(T*) * this->rows);



    for(int i = 0; i < this->rows; i++)
    {
        this->ptr[i] = (T*)malloc(sizeof(T) * this->columns);

        for(int j = 0; j < this->columns; j++)
        {
            this->ptr[i][j] = T();
        }
    }
}

template <int R, int C,typename T>
void Matrix<R,C,T>::setEntry(int row, int column, T data)
{
    this->ptr[row][column] = data;
}

template <int R, int C,typename T>
T Matrix<R,C,T>::getEntry(int row, int column) const
{
    return ptr[row][column];
}

template <int R, int C,typename T>
std::string Matrix<R,C,T>::toString() const
{
    std::string ret = "";
    for(int i = 0; i < this->rows;i++)
    {
        for(int j = 0;j < this->columns;j++)
        {
            //(*this->toStringFunction)
            ret += this->ptr[i][j]._toStringOf(this->ptr[i][j]) + ", ";
        }
        ret += "\n";
    }
    return ret;
}

template <int R, int C,typename T>
template <int J>
Matrix<R,J,T> Matrix<R,C,T>::operator*(const Matrix<R,J,T>& mat) const
{
    Matrix<R,J,T> ret = Matrix<R,J,T>();
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < J; j++)
        {
            T val = 0.0;
            for(int k = 0; k < C; k++)
            {
                val = val + mat.getEntry(k, j) * this->getEntry(i, k);

            }
            ret.setEntry(i, j, val);
        }
    }    
    return ret;
}
template <int R, int C,typename T>
Matrix<R,C,T> Matrix<R,C,T>::operator+(const Matrix<R,C,T>& mat) const
{
    Matrix<R,C,T> ret = Matrix<R,C,T>();
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            ret.setEntry(i, j, this->getEntry(i, j) + mat.getEntry(i, j));
        }
    }    
    return ret;
}
template <int R, int C,typename T>
Matrix<R,C,T> Matrix<R,C,T>::operator*(const T& n) const
{
    Matrix<R,C,T> ret = Matrix<R,C,T>();
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            ret.setEntry(i, j, this->getEntry(i, j) * n);
        }
    }    
    return ret;
}

template <int R, int C,typename T>
Matrix<R,C,T> Matrix<R,C,T>::RRef() const
{
    Matrix<R,C,T> ret = Matrix<R,C,T>();
    
    for(int i = 0;i < R;i++)
    {
        for(int j = 0; j < C;j++)
        {
            ret.setEntry(i, j, this->getEntry(i, j));
        }
    }
    
    for(int i = 0; i < C - 1; i++)
    {
        int maxEntry = 0;
        float maxMagnitude = -0.01;

        int usedRows[R] = {};

        for(int k = 0; k < R;k++)
        {
            usedRows[k] = -1;
        }

        for(int j = 0; j < R; j++)
        {
            bool flag = false;
            for(int k = 0;k < i;k++)
            {
                if(usedRows[k] == j)
                {
                    flag = true;
                }
            }
            if(flag)
            {
                continue;
            }
            //std::cout << ret.getEntry(j,i).toString() << "\t" << ret.getEntry(j,i)._magnitudeOf(ret.getEntry(j,i)) << "MAG\n";
            if(ret.getEntry(j,i)._magnitudeOf(ret.getEntry(j,i)) > maxMagnitude)
            {
                maxEntry = j;
                maxMagnitude = ret.getEntry(j,i)._magnitudeOf(ret.getEntry(j,i));
            }
        }



        if(maxMagnitude < MAGNITUDE_CUTOFF)
        {
            continue;
        }

        usedRows[i] = maxEntry;

        for(int j = 0; j < R; j++)
        {
            if(j == maxEntry)
            {
                continue;
            }

            if( ret.getEntry(j,i)._magnitudeOf(ret.getEntry(j,i)) > MAGNITUDE_CUTOFF)
            {
                for(int k = 0; k < C;k++)
                {
                    if(k == i)
                    {
                        continue;
                    }
                    ret.setEntry(j, k, ret.getEntry(maxEntry, k) - ret.getEntry(j, k) * ret.getEntry(maxEntry, i) / ret.getEntry(j, i));
                }
                ret.setEntry(j, i, T());

            }
            //std::cout << ret.toString() << "\n\n";
            
        }

        
    }    

    for(int i = 0; i < R;i++)
    {
        int maxEntry = 0;
        float maxMagnitude = -0.01;
        
        for(int j = 0;j < C - 1;j++)
        {
            if( ret.getEntry(i,j)._magnitudeOf(ret.getEntry(i, j)) > maxMagnitude)
            {
                maxMagnitude =  ret.getEntry(i,j)._magnitudeOf(ret.getEntry(i, j));
                maxEntry = j;
            }

        }
        //std::cout << maxEntry << "\n";
        if(maxMagnitude < MAGNITUDE_CUTOFF)
        {
            continue;
        }
        //std::cout << C << "\n";
        for(int k = C - 1; k >= 0 ; k--)
        {
            //std::cout << k <<"{}" <<  ret.getEntry(i, k)<< " k  \n";
            //std::cout << ret.getEntry(i, k) / ret.getEntry(i, maxEntry) << " RES\n\n";
            ret.setEntry(i, k, ret.getEntry(i, k) / ret.getEntry(i, maxEntry));
        }
        //std::cout << "\n";
    
    }
    return ret;
}




#endif