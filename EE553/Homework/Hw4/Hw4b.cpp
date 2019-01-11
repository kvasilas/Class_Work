/*

  * Hw4a - Vec3d
  * Kirk Vasilas
  * Collaborators - Christopher Keenan, Kevin L.
  *I pledge my honor that i have abided by the stevens honor code

 */
#include<iostream>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<chrono>
#include <time.h>
using namespace std;

class JulianDate {
private:
  static int EPOCH;
//	int mon, day, year, hour, min, second;
// this representation would make difference VERY UGLY
// diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
	double jday; // each 1 is 1 day
	//static JulianDate J2000;
public:
  JulianDate() {
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
    int k, m, i, ut, min, sec;
    k = gmtm->tm_year;
    m = gmtm->tm_mon;
    i = gmtm->tm_mday;
    ut = double(gmtm->tm_hour);
    min = double(gmtm->tm_min);
    sec = double(gmtm->tm_sec);
    min += (sec/60);
		ut += (min/60);

    jday = 367 * k - trunc(7*(k+int((m+9)/12))/4) + trunc(275*m/9)+ i + 1721013.5 + (ut/24) - (0.5 * (100 * k + m - 190002.5) / abs(100 * k + m - 190002.5)) + 0.5;
  }

    JulianDate(int k, int m, int i, double ut, double min, double sec ) : jday(jday){
		    min += (sec/60);
		    ut += (min/60);
		    jday = 367 * k - trunc(7*(k+int((m+9)/12))/4) + trunc(275*m/9)+ i + 1721013.5 + (ut/24) - (0.5 * (100 * k + m - 190002.5) / abs(100 * k + m - 190002.5)) + 0.5;
	  }

    JulianDate(int k, int m, int i) : jday(jday){
		    double ut = 0;
		    jday = 367 * k - trunc(7*(k+int((m+9)/12))/4) + trunc(275*m/9)+ i + 1721013.5 + (ut/24) - (0.5 * (100 * k + m - 190002.5) / abs(100 * k + m - 190002.5)) + 0.5;
	   }

    friend ostream& operator <<(ostream& s, JulianDate d){
		   return s << setprecision(15) << d.jday;
	  }

    friend double operator -(JulianDate d1 , JulianDate d2){
		    return d1.jday - d2.jday;
	  }

    friend JulianDate operator +(JulianDate d1, int n){
		JulianDate ans = d1;
		ans.jday = d1.jday + n;
		return ans;
  }

    double getYear() const {
      double dy = (jday - 2000)/365;
      int ans = dy/365;
      return ans;
    }
    double getMonth() const {
      double dy = (jday - 2000)/(365*365);
      int ans = (dy)*12;
      return ans;
    }
    double getDay() const {
      double dy = (jday - 2000)/(365*365);
      int ans = dy*365;
      return ans;
    }
    double getHour() const {
      double dy = (jday - 2000)/(365*365);
      int ans = dy*24;
      return ans;
    }
    double getMin() const {
      double dy = (jday - 2000)/(365*365);
      int ans = dy*24*60;
      return ans;
    }
    double getSec() const {
      double dy = (jday - 2000)/(365*365);
      int ans = dy*24*60*60;
      return ans;
    }
};

int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
  JulianDate newyear(2018, 1, 1, 0,0,0);
	JulianDate valentine(2018, 2, 14, 12,0,0);
	JulianDate today; // get it from the system time: time(nullptr)
	                  // localtime

	double days = valentine - newyear;
	JulianDate due = today + 7;
	cout << due << '\n';
  cout << newyear << endl;
	cout << "\nyear: " << newyear.getYear()
	     << "\nmonth: " << newyear.getMonth()
       << "\nday: " << newyear.getDay()
			 << "\nhour: " << newyear.getHour()
			 << "\nmin: " << newyear.getMin()
			 << "\nsec: " << newyear.getSec() << '\n';

  return 0;
}
