#include "horloge.h"

std::time_t Horloge::t=time(NULL);
std::tm* Horloge::now=nullptr;

void Horloge::definir_temps()
{
    t = time(NULL);
    now = localtime(&t);
}

std::string Horloge::donner_jr_sem(){ return jours[now->tm_wday];   }
int Horloge::donner_jr_mois()       { return now -> tm_mday;        }
std::string Horloge::donner_mois()  { return mois[now->tm_mon];     }
int Horloge::donner_annee()         { return now -> tm_year+1900;   }
int Horloge::donner_heure()         { return now -> tm_hour;        }
int Horloge::donner_min()           { return now -> tm_min;         }
int Horloge::donner_sec()           { return now -> tm_sec;         }



Chronom::Chronom()
{
    heure = minute = seconde = 0;
    debut = std::chrono::steady_clock::now();
    fin = debut;
    duree=fin-debut;
}

int Chronom::donner_chrono_heure()  { return heure;     }
int Chronom::donner_chrono_min()    { return minute;    }
int Chronom::donner_chrono_sec()    { return seconde;   }

void Chronom::chronometrer()
{
    fin=std::chrono::steady_clock::now();
    duree = fin-debut;
    int duree_int = duree.count();
    heure = duree_int / 3600;
    minute = (duree_int/60) % 60;
    seconde =  duree_int % 60;
}

void Chronom::chrono_a_zero()
{
    debut = std::chrono::steady_clock::now();
}



Rebour::Rebour()
{
    heure_restant = sec_restant = min_restant = total_sec = sec_ecoules = 0;
}

void Rebour::decompter(int hh, int mm, int ss )
{
    total_sec = ((hh*60 + mm) * 60) + ss;
    chrono.chronometrer();
    sec_ecoules = total_sec - chrono.duree.count();
    if ( sec_ecoules >=0 )
    {
        heure_restant = hh - chrono.heure;
        min_restant = (sec_ecoules/60) % 60;
        sec_restant = sec_ecoules % 60;
    }
}

int Rebour::donner_rebours_heure() { return heure_restant;   }
int Rebour::donner_rebours_min()   { return min_restant;     }
int Rebour::donner_rebours_sec()   { return sec_restant;     }
int Rebour::donner_sec_ecoules()   { return sec_ecoules;     }
void Rebour::rebour_a_zero()       { chrono.chrono_a_zero(); }



Alarm::Alarm() { val = false; }

bool Alarm::est_heure(int heure, int minute)
{

    if ( heure==horloge.donner_heure() && minute==horloge.donner_min() )
        val=true;
    else
        val=false;
    return val;
}
