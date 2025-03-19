#ifndef HORLOGE_H_INCLUDED
#define HORLOGE_H_INCLUDED

#include <ctime>
#include <chrono>
#include <string>

class Horloge
{
    private :
        std::string jours[7]={"Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi"},
                    mois[12]={"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout",
                    "Septembre","Octobre","Novembre","Décembre"};
        static std::time_t t;
        static std::tm* now;
    public :
        void        definir_temps();
        std::string donner_jr_sem();
        int         donner_jr_mois();
        std::string donner_mois();
        int         donner_annee();
        int         donner_heure();
        int         donner_min();
        int         donner_sec();


};

class Rebour;
class Chronom
{
    private :
        int heure, minute, seconde;
        std::chrono::steady_clock::time_point debut ;
        std::chrono::steady_clock::time_point fin ;
        std::chrono::duration<double> duree ;

    public :
        Chronom();
        void chronometrer();
        void chrono_a_zero();
        int donner_chrono_heure();
        int donner_chrono_min();
        int donner_chrono_sec();
        friend class Rebour;

};

class Rebour
{
        Chronom chrono;
        int heure_restant, min_restant, sec_restant, total_sec, sec_ecoules;
    public :
        Rebour();
        void decompter(int,int,int);
        void rebour_a_zero();
        int donner_sec_ecoules();
        int donner_rebours_heure();
        int donner_rebours_min();
        int donner_rebours_sec();

};

class Alarm
{
    private :
        Horloge horloge;
        bool val;
    public :
        Alarm();
        bool est_heure(int,int);


};
#endif // HORLOGE_H_INCLUDED
