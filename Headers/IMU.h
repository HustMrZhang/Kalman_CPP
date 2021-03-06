#ifndef IMU_H
#define IMU_H
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>
#include <ctime>
#include "DataReader.h"

class IMU {

        //Attributs
        private :
        std::vector<double> *data;         //Buffer des données GPS, contient X,Y,Z et CovX,CovY et CovZ
        std::vector<double> *data_vitesse;         //Buffer des données GPS, contient vitesse X,Y,Z et CovX,CovY et CovZ
        std::string topic_name;
        DataReader *reader;
        double timeStamp;
        int sizeMess;
        
        //Fonctions
        public :
                //Constructeur et Destructeur
                IMU(std::string name, int s);
                ~IMU();

                //Getteurs
                std::vector<double>* getData();
                std::vector<double>* getVitesse();
                std::string getTopic();
                DataReader* getDataReader();
                double getTimeStamp();
                int getSizeMess();

                //Setteurs
                void setTimeStamp(double);
                void setTopic(std::string);
                
                //Afichage
                void Display();
                void Acquisition();
                void Analysis();

                std::vector<std::string> split2(const std::string &s, char delim, std::vector<std::string> &elems);
                std::vector<std::string> split(const std::string &s, char delim);


};

#endif
