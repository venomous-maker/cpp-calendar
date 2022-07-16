#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// Function to return the day of the month or year on which a certain date stands
// It takes day, month and year arguments
int dayNumber(int day, int month, int year){
   static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   year -= month < 3;
   return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

// 	This Function returns a month name basing on the month number argument
string getMonthName(int monthNumber){
   string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   return (months[monthNumber]);
}

// The function returns the number of days in a certain year or month it takes month number and year as arguments
int numberOfDays (int monthNumber, int year){
   switch(monthNumber){
      case 0 :
      case 2 :
      case 4 :
      case 6 :
      case 7 :
      case 9 :
      case 11: return(31);
      break;
      case 1 :
      // Determining Leap year or common year using if function and assign February specific days
         if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0)){
            return (29);
		}
         else
        {
            return (28);
        }
      break;
      case 3 :
      case 5 :
      case 8 :
      case 10 : return(30);
      break;
   }
   return 0;
}


// The Function returns either Leap or Common Year
string YearType(int year)
{
	string year_type;
	if (year % 4 != 0)
	{
        year_type = "Common Year";
	}
    else if (year % 100 !=0)
    {
        year_type = "Leap Year";
    }
    else if(year % 400 != 0)
    {
		year_type = "Common Year";
	}
	else
	{
		year_type = "Leap Year";
	}
    return (year_type);
}

// The function that prints out the calendar either yearly or monthly
void printCalendar(int year){
   int days, month_num;
   // Display calendar for a month or a specified year(option input variable)
   std::string option;
   cout<<"Do you want me to display one month calendar?(Input Yes or No): ";
   cin>>option;
   
   // convert string to upper case to avoid case sensitive inputs
   std::for_each(option.begin(), option.end(), [](char & c) {
       c = ::toupper(c);
    });
    
    // Outputs year and year type either leap or common
   cout<<"\t\t\t Calendar - Year "<<year<<" "<<YearType(year);
   
   //Printing calendar for a whole year
    if (option == "NO")
    {
       int days;
       int current = dayNumber (1, 1, year);;
   for (int i = 0; i < 12; i++){
      days = numberOfDays (i, year);
      cout<<endl<<"       "<<getMonthName (i).c_str()<<"  "<<year<<"     "<<endl;
      cout<<"Sun Mon Tue Wed Thu Fri Sat\n";
      int k;
      std::string sp, digit_len;
		for (k = 0; k < current; k++)
			if (current == 6)
			{
				sp = "                       ";
			}
			if (current == 5)
			{
				sp = "                   ";
			}
			if (current == 4)
			{
				sp = "               ";
			}
			if (current == 3)
			{
				sp = "           ";
			}
			if (current == 2)
			{
				sp = "       ";
			}
			if (current == 1)
			{
				sp = "   ";
			}
			if (current == 0)
			{
				sp = "";
			}
			std::cout<<sp;
      for (int j = 1; j <= days; j++){
		  digit_len = to_string(j);
		  if (digit_len.size() == 2)
		  {
			  if (k == 0){
         printf(" %d", j);
		}
		else
		{
			printf("  %d", j);
		}
		  }
		  else
		  {
			 	  if (k == 0){
         printf("  %d", j);
		}
		else
		{
			printf("   %d", j);
		}
		  }
	 
         if (++k > 6){
            k = 0;
            cout<<endl;
         }
      }
      if (k)
         cout<<endl;
         current = k;
      }
    }
    
    // Printing for a specific month
    else if (option == "YES")
    {
		cout<<"\nWhich Month Do You Want Me To Generate A Calendar For? (Use Inntegers e.g 1 or 12): ";
		cin>> month_num;
		if (month_num > 12 || month_num <1)
		{
			cout<<"Invalid month input "<<month_num;
		}
		else{
		int current = dayNumber (1, month_num, year);
      days = numberOfDays (month_num-1, year);
      cout<<endl<<"       "<<getMonthName (month_num-1).c_str()<<"  "<<year<<"     "<<endl;
      cout<<"Sun Mon Tue Wed Thu Fri Sat\n";
      int k;
      std::string sp, digit_len;
		for (k = 0; k < current; k++)
			if (current == 6)
			{
				sp = "                       ";
			}
			if (current == 5)
			{
				sp = "                   ";
			}
			if (current == 4)
			{
				sp = "               ";
			}
			if (current == 3)
			{
				sp = "           ";
			}
			if (current == 2)
			{
				sp = "       ";
			}
			if (current == 1)
			{
				sp = "   ";
			}
			if (current == 0)
			{
				sp = "";
			}
			std::cout<<sp;
      for (int j = 1; j <= days; j++){
		  digit_len = to_string(j);
		  if (digit_len.size() == 2)
		  {
			  if (k == 0){
         printf(" %d", j);
		}
		else
		{
			printf("  %d", j);
		}
		  }
		  else
		  {
			 	  if (k == 0){
         printf("  %d", j);
		}
		else
		{
			printf("   %d", j);
		}
		  }
	 
         if (++k > 6){
            k = 0;
            cout<<endl;
         }
      }
      if (k)
         cout<<endl;
         current = k;
      }
	}
   return;
}

int main(){
   unsigned int year;
   string option, digit_len;
   cout<<"Input The year: ";
   cin>> year;
   digit_len = to_string(year);
   
   // Validating user input for year
   if (digit_len.size() != 4)
   {
	 cout<<"Invalid input for year "<<digit_len.size()<<"!!! use a four digit integer";  
	}
	else
	{
   printCalendar(year);
	}
   return (0);
}
