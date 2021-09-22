#ifndef _MATRIX_H__
#define _MATRIX_H__

#include<string>
#include<array>
#include<iostream>
template <int R, int C,typename T>
class Matrix
{
    private:
        int rows;
        int columns;
        std::string (*toStringFunction)(T x);
        float (*magnitudeFunction)(T x);
        //Pointer to array of _rows_ pointers to each row array
        T** ptr;
        T defaultValue;


    public:
        Matrix<R,C,T>(std::string  (*tSF)(T), float (*magF)(T), std::array<T, R*C> const& data, T defaultValue);
        Matrix<R,C,T>(std::string  (*tSF)(T), float (*magF)(T), T defaultValue);


        void setEntry(int row, int column, T data);
        T getEntry(int row, int column);

        //Matrix<T> operator*(const Matrix<T>& mat);
        template<int J>
        Matrix<R,J,T> operator*(Matrix<R,J,T>& mat);

        Matrix<R,C,T> operator+(Matrix<R,C,T>& mat);
        Matrix<R,C,T> operator*(const T& n);

        Matrix<R,C,T> RRef();

        std::string toString();

        //std::string (*pm)(T) getToStringFunction();





};



template <int R, int C,typename T>
Matrix<R,C,T>::Matrix(std::string  (*tSF)(T), float (*magF)(T), std::array<T, R*C> const& data, T defaultValue)
{   
    this->rows = R;
    this->columns = C;
    this->ptr = new T*[this->rows];
    this->toStringFunction = tSF;
    this->defaultValue = defaultValue;
    this->magnitudeFunction = magF;

    for(int i = 0; i < this->rows; i++)
    {
        this->ptr[i] = new T[this->columns];

        for(int j = 0; j < this->columns; j++)
        {
            this->ptr[i][j] = data[j + i * this->columns];
        }
    }
}

template <int R, int C,typename T>
Matrix<R,C,T>::Matrix(std::string  (*tSF)(T), float (*magF)(T) , T defaultValue)
{   
    
    this->rows = R;
    this->columns = C;
    this->ptr = new T*[this->rows];
    this->toStringFunction = tSF;
    this->defaultValue = defaultValue;
    this->magnitudeFunction = magF;

    for(int i = 0; i < this->rows; i++)
    {
        this->ptr[i] = new T[this->columns];

        for(int j = 0; j < this->columns; j++)
        {
            this->ptr[i][j] = defaultValue;
        }
    }
}

template <int R, int C,typename T>
void Matrix<R,C,T>::setEntry(int row, int column, T data)
{
    this->ptr[row][column] = data;
}

template <int R, int C,typename T>
T Matrix<R,C,T>::getEntry(int row, int column)
{
    return ptr[row][column];
}

template <int R, int C,typename T>
std::string Matrix<R,C,T>::toString()
{
    std::string ret = "";
    for(int i = 0; i < this->rows;i++)
    {
        for(int j = 0;j < this->columns;j++)
        {
            ret += (*this->toStringFunction)(this->ptr[i][j]) + ", ";
        }
        ret += "\n";
    }
    return ret;
}

template <int R, int C,typename T>
template <int J>
Matrix<R,J,T> Matrix<R,C,T>::operator*(Matrix<R,J,T>& mat)
{
    Matrix<R,J,T> ret = Matrix<R,J,T>(this->toStringFunction, this->magnitudeFunction, this->defaultValue);
    
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
Matrix<R,C,T> Matrix<R,C,T>::operator+(Matrix<R,C,T>& mat)
{
    Matrix<R,C,T> ret = Matrix<R,C,T>(this->toStringFunction, this-> magnitudeFunction, this->defaultValue);
    
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
Matrix<R,C,T> Matrix<R,C,T>::operator*(const T& n)
{
    Matrix<R,C,T> ret = Matrix<R,C,T>(this->toStringFunction, this->magnitudeFunction , this->defaultValue);
    
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
Matrix<R,C,T> Matrix<R,C,T>::RRef()
{
    Matrix<R,C,T> ret = Matrix<R,C,T>(this->toStringFunction, this->magnitudeFunction, this->defaultValue);
    
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

            if((*ret.magnitudeFunction)(ret.getEntry(j,i)) > maxMagnitude)
            {
                maxEntry = j;
                maxMagnitude = (*ret.magnitudeFunction)(ret.getEntry(j,i));
            }
        }



        if(maxMagnitude < 0.000001)
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

            if((*ret.magnitudeFunction)(ret.getEntry(j,i)) > 0.000001)
            {
                for(int k = 0; k < C;k++)
                {
                    if(k == i)
                    {
                        continue;
                    }
                    ret.setEntry(j, k, ret.getEntry(maxEntry, k) - ret.getEntry(j, k) * ret.getEntry(maxEntry, i) / ret.getEntry(j, i));
                }
                ret.setEntry(j, i, ret.defaultValue);

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
            if((*ret.magnitudeFunction)(ret.getEntry(i, j)) > maxMagnitude)
            {
                maxMagnitude = (*ret.magnitudeFunction)(ret.getEntry(i, j));
                maxEntry = j;
            }

        }
        //std::cout << maxEntry << "\n";
        if(maxMagnitude < 0.000001)
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