#ifndef CODEWORD_H
#define CODEWORD_H
#include <iostream>
#include <vector>

//CODEWORD
template<typename T>
class Codeword
{
        std::vector<T> data;
    public:
        int distance(Codeword<T>);
        Codeword(std::vector<T>);
        void display();
        int Weight();
};



template<typename T>
Codeword<T>::Codeword(std::vector<T> d)
{
    data = d;
}

//Print out elements and weight of a codeword
template<typename T>
void Codeword<T>::display()
{
    for(int i=0; i<data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << "Weight: "<< Weight() <<std::endl;
}

//Finding the weight of a codeword
template<typename T>
int Codeword<T>::Weight()
{
    int weight=0;
    for(int i=0;i<data.size();i++)
    {
        if(data[i].getValue()!=0)
            weight++;
    }
    return weight;
}

//Finding distance between two codewords
template<typename T>
int Codeword<T>::distance(Codeword<T> c)
{
    int dist = 0;
    for(int i=0;i<data.size();i++){
        dist = dist + (data[i] - c.data[i]);
    }
    
    return dist;
}


//Distance class to store distance calculated and display
class Distance
{
        int *dist;
        int size;
    public:
        Distance(int*, int);
        int getValue(int);
        void display();
};

Distance::Distance(int *d, int s)
{
    size = s;
    dist = new int[size];
    for(int i=0;i<size;i++)
        dist[i] = d[i];
}

void Distance::display()
{
    for(int i=0;i<size;i++){
        std::cout << dist[i] <<"  ";
    }
}

int Distance::getValue(int i)
{
    return dist[i];
}


//CODEBOOK
template<typename T>
class Codebook
{
    private:
        std::vector<Codeword<T>> codeword;
        std::vector<Distance> distances;
    public:
        void add(Codeword<T>);
        int minimumWeight();
        void calDistance();
        void display();
        int minimumDistance();
};


template<typename T>
void Codebook<T>::add(Codeword<T> c)
{
    codeword.push_back(c);
}

//Display all codewords, weights, minimum weight, distance matrix and minimum distance
template<typename T>
void Codebook<T>::display()
{
    for(int i=0; i<codeword.size(); i++)
    {
        codeword[i].display();
    }
    std::cout << "Minimum weight: " << minimumWeight() << std::endl;
    std::cout << std::endl;
    std::cout << "Distance matrix: " << std::endl;
    
    calDistance();
    
    for(int i=0;i<distances.size();i++)
        {
            distances[i].display();
            std::cout << std::endl;
        }
    std::cout << "Minimum distance: " << minimumDistance() << std::endl;
}

//Calculate minimum weight
template<typename T>
int Codebook<T>::minimumWeight()
{
    int min=9999;
    for(int i=1; i<codeword.size(); i++)
    {
        int weight = codeword[i].Weight();
        if(weight < min)
            min = weight;
    }
    return min;
}

//Calculate distance between codewords
template<typename T>
void Codebook<T>::calDistance()
{   
    
    int size = codeword.size();
    for(int i=0;i<size;i++){
        int *dist = new int[size];
        for(int j=0;j<size;j++){
            int result = codeword[i].distance(codeword[j]);
            dist[j] = result;
        }
        Distance distance(dist,size);
        distances.push_back(distance);
    }
}

//Calculate minimum distance
template<typename T>
int Codebook<T>::minimumDistance()
{
    int min=9999;
    for(int i=0;i<distances.size();i++)
    {
        for(int j=0;j<distances.size();j++)
        {
            int distance = distances[i].getValue(j);
            if(distance < min && distance!=0) 
                min = distance;
        }
    }
    return min;
}

#endif // CODEWORD_H

