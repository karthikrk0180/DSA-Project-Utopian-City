#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 9999
#define V 12

//COUNTS
int node_count = 0;
int cflag = 0;
int house_count = 0;
int office_count = 0;
int hospital_count = 0;
int industry_count = 0;
int garden_count = 0;
int school_count = 0;
int police_station_count = 0;
int restaurant_count = 0;
int college_count = 0;
int shop_count = 0;
int bus_count = 0;
int busstand_count = 0;
int market_count = 0;
int graph_count = 0;

int *array[30];
int cost_matrix[V][V]= {0};
int flood_matrix[V][V]= {0};
int visited[V];
int source=0;
int c=0;
int dist[V];
int path[V];
//STRUCTURE DEFINITIONS
struct hashing
{
    int flag;
    char password[20];
};
struct hashing hash[1000];

struct house
{
    char house_name[30];
    int house_number;
    int house_people;
    char house_location[30];
    char house_password[30];
};
struct house home[30];

struct office
{
    char office_name[20];
    int num_of_employees;
    char office_type[20];
    char office_location[20];
    int working_hours;
    long long int contact_no;
};
struct office off[10];

struct hospital
{
    char hospital_name[20];
    char hospital_location[20];
    int hospital_rating;
    char hospital_type[10];
    int num_of_doctors;
    long long int contact_no;
};
struct hospital hosp[10];

struct school
{
    char school_name[20];
    int school_working_hours;
    long long int contact_no;
    int school_location[20];
    int school_rating;
};
struct school skool[10];

struct city_bus
{
    int bus_num;
    char from[30];
    char to[30];
    int num_of_stops;
};
struct city_bus buses[20];

struct city_busstand
{
    char busstand_name[30];
    char busstand_location[30];
    struct city_bus buses[20];
};
struct city_busstand cb;

struct market
{
    char market_name[10];
    char market_location[20];
    float open_time;
    float close_time;
};
struct market m;

struct industry
{
    char industry_name[20];
    char location[20];
    int industry_no;
    char industry_type[20];
    int no_of_employees;
};
struct industry industries[10];

struct police_station
{
    char station_name[20];
    char location[20];
    int no_of_constables;
    int no_of_inspectors;
    int no_of_cells;
    int max_criminals;
};
struct police_station stations[10];

struct garden
{
    char garden_name[20];
    char location[20];
    double area;
    char start_time[20];
    char close_time[20];
};
struct garden parks[10];

struct restaurants
{
    char name[20];
    int no_of_workers;
    char type[20];
    int working_hours;
    int rating;
    char location[20];
};
struct restaurants hotels[10];

struct college
{
    char name[20];
    char type[20];
    char location[20];
    int no_of_students;
    int no_of_professors;
    int rating;
    double fee_structure;
};
struct college edu_institution[10];

struct shops
{
    char name[20];
    char type[20];
    char location[20];
};
struct shops store[10];

struct nodes
{
    char nodes_name[20];
};
struct nodes Node_Names[12];

struct graph
{
    int u;
    int v;
    int w;
};
struct graph s[20];


struct tree
{
    struct college data;
    struct tree *left;
    struct tree * right;
};
typedef struct tree TREE;



//PROTOTYPES OF THE FUNCTIONS
void check();
void menu();
///////////////////////////////////////////////////
void add_house();
void add_hospital();
void add_office();
void add_school();
void add_garden();
void add_industry();
void add_police_station();
void add_college();
void add_shops();
void add_restuarants();
void add_market();
void add_bus();
void add_busstand();
void add_nodes();
/////////////////////////////////////////////////////
void print_school();
void print_industry();
void print_houses();
void print_police_station();
void print_restuarants();
void print_college();
void print_shops();
void print_office();
void print_hospital();
void print_market();
void print_busstand();
void print_bus();
void print_garden();
///////////////////////////////////////////////////
void floyd();
void hashing();
void marathon();
void search();
void Buildings();
void flood_evacuation();//dfs
void check_floyd();
void sort_industries();
void sort_restaurants();
void kruskals();
int min(int, int );
void floyd(int matrix[20][20], int );
int hashpassword(char []);
void swap(struct industry, struct industry );
int partition(struct industry industries[], int, int );
void quickSort(struct industry industries[], int, int );
int search_house(char [], char []);
int kruskals_sum(struct graph [], int [], int, int );
void dfs(int flood_matrix[12][12],int,int,int []);
void bfs(int cost_matrix[V][V],int,int, int []);
void sort(struct graph [], int );
int find(int [], int, int );
void union1(int [], int, int, int );
TREE * insert_into_bst(TREE *root,struct college data);
void inorder(TREE *root);
void preorder(TREE *root);
void postorder(TREE *root);
void Dijkstras();

int main()
{
    menu();
    int choice;
    while (1)
    {
        printf("\nAdd your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 0:
            check();
            break;

        case 1:
            add_house();

            add_office();

            add_hospital();

            add_industry();

            add_garden();

            add_school();

            add_bus();

            add_busstand();

            add_market();

            add_police_station();

            add_restuarants();

            add_college();

            add_shops();

            add_nodes();

            if(cflag == 0)
                printf("Files read successfully\n");
            else
                printf("Files not read successfully\n");
            break;

        case 2:
            print_houses();

            print_school();

            print_office();

            print_hospital();

            print_market();

            print_industry();

            print_police_station();

            print_garden();

            print_restuarants();

            print_college();

            print_shops();

            print_bus();

            print_busstand();
            break;

        case 3:
            check_floyd();
            break;

        case 4:
            sort_restaurants();
            break;

        case 5:
            sort_industries();
            break;

        case 6:
            hashing();
            break;

        case 7:
            flood_evacuation();
            break;

        case 8:
            marathon();
            break;

        case 9:
            search();
            break;

        case 10:
            kruskals();
            break;

        case 11:
            BST();
            break;

        case 12:
            Dijkstras();
            break;


        default:
            exit(0);
        }
    }
    return 0;
}

/*
    Function : check
    Input_type:NULL
    Description : Checks the status of city by mentioning the buildings with its count
*/
void check()
{
    printf("There are %d houses in the city\n", house_count);
    printf("There are %d offices in the city\n", office_count);
    printf("There are %d hospitals in the city\n", hospital_count);
    printf("There are %d industries in the city\n", industry_count);
    printf("There are %d gardens in the city\n", garden_count);
    printf("There are %d schools in the city\n", school_count);
    printf("There are %d bus in the city\n", bus_count);
    printf("There are %d bus stand in the city\n", busstand_count);
    printf("There are %d market in the city\n", market_count);
    printf("There are %d police station in the city\n", police_station_count);
    printf("There are %d restaurants in the city\n", restaurant_count);
    printf("There are %d colleges in the city\n", college_count);
    printf("There are %d shops in the city\n", shop_count);
}

// Menu for the program
void menu()
{
    printf("\n------------Menu------------\n\n");
    printf("1. Add buildings to the city\n");
    printf("2. Print all buildings in the city\n");
    printf("3. Apply Floyd's Algorithm on the city\n");
    printf("4. Sort restaurants according to the ratings\n");
    printf("5. Sort industries\n");
    printf("6. Hashing\n");
    printf("7. Flood evacuation\n");
    printf("8. Marathon\n");
    printf("9. Search house\n");
    printf("10. Kruskals\n");
    printf("11. BST\n");
    printf("12.Finding Shortest path using Dijkstras");
    printf("\n-----------------------------\n");
}

/*
    Function : add_house
    Description : Adds a new house in the city
*/
void add_house()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("House.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        perror("File not found\n");
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s", home[house_count].house_name);
        fscanf(fp, "%d", &home[house_count].house_number);
        fscanf(fp, "%d", &home[house_count].house_people);
        fscanf(fp, "%s", home[house_count].house_location);
        fscanf(fp, "%s\n", home[house_count].house_password);

        // update house_count after adding a house in the city
        house_count++;
    }

    fclose(fp);
}

/*
    Function : add_school()
    Description : Adds a new school in the city
*/

void add_school()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("School.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", skool[school_count].school_name);
        fscanf(fp, "%d\n", &skool[school_count].school_working_hours);
        fscanf(fp, "%lld\n", &skool[school_count].contact_no);
        fscanf(fp, "%s\n", skool[school_count].school_location);
        fscanf(fp, "%d\n", &skool[school_count].school_rating);

        // update school_count after adding a school in the city
        school_count++;
    }

    fclose(fp);
}

/*
    Function : add_hospital
    Description : Adds a new hospital in the city
*/

void add_hospital()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Hospital.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", hosp[hospital_count].hospital_name);
        fscanf(fp, "%s\n", hosp[hospital_count].hospital_location);
        fscanf(fp, "%d\n", &hosp[hospital_count].hospital_rating);
        fscanf(fp, "%s", hosp[hospital_count].hospital_type);
        fscanf(fp, "%d\n", &hosp[hospital_count].num_of_doctors);
        fscanf(fp, "%lld\n", &hosp[hospital_count].contact_no);

        // update hospital_count after adding a hospital in the city
        hospital_count++;
    }

    fclose(fp);
}

/*
    Function : add_office
    Description : Adds a new office in the city
*/

void add_office()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Office.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", off[office_count].office_name);
        fscanf(fp, "%d\n", &off[office_count].num_of_employees);
        fscanf(fp, "%s\n", off[office_count].office_type);
        fscanf(fp, "%s", off[office_count].office_location);
        fscanf(fp, "%d", &off[office_count].working_hours);
        fscanf(fp, "%lld", &off[office_count].contact_no);

        // update office_count after adding a office in the city
        office_count++;
    }

    fclose(fp);
}
/*
    Function : add_bus
    Description : Adds a new bus to the busstand
*/
void add_bus()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Bus.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%d\n", &buses[bus_count].bus_num);
        fscanf(fp, "%s\n", buses[bus_count].from);
        fscanf(fp, "%s\n", buses[bus_count].to);
        fscanf(fp, "%d", &buses[bus_count].num_of_stops);

        // update bus_count after adding a bus in the city
        bus_count++;
    }

    fclose(fp);
}
/*
    Function : add_busstand
    Description : Adds a new bus stand in the city
*/
void add_busstand()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Bus_Stand.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", cb.busstand_name);
        fscanf(fp, "%s\n", cb.busstand_location);
        for (int i = 0; i < bus_count; i++)
        {
            fscanf(fp, "%d\n", &cb.buses[i].bus_num);
        }

        // updates busstand_count after adding a busstand in the city
        busstand_count++;
    }

    fclose(fp);
}
/*
    Function : add_market
    Description : Adds a new market in the city
*/
void add_market()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Market.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", m.market_name);
        fscanf(fp, "%s\n", m.market_location);
        fscanf(fp, "%f\n", &m.open_time);
        fscanf(fp, "%f", &m.close_time);

        // updates market_count after adding a market in the city
        market_count++;
    }

    fclose(fp);
}

/*
    Function : add_industry
    Description : adds an industry of required properties to the city
*/
void add_industry()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Industry.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", industries[industry_count].industry_name);
        fscanf(fp, "%s\n", industries[industry_count].location);
        fscanf(fp, "%d\n", &industries[industry_count].industry_no);
        fscanf(fp, "%s\n", industries[industry_count].industry_type);
        fscanf(fp, "%d\n", &industries[industry_count].no_of_employees);

        // update industry_count after adding a industry in the city
        industry_count++;
    }
    fclose(fp);
}

/*
    Function : add_garden
    Description : Adds a garden of required properties to the city
*/

void add_garden()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Garden.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", parks[garden_count].garden_name);
        fscanf(fp, "%s\n", parks[garden_count].location);
        fscanf(fp, "%lf\n", &parks[garden_count].area);
        fscanf(fp, "%s\n", parks[garden_count].start_time);
        fscanf(fp, "%s\n", parks[garden_count].close_time);

        // update garden_count after adding a garden in the city
        garden_count++;
    }
    fclose(fp);
}

/*
    Function : add_college
    Description : adds an college_count of required properties to the city
*/

void add_college()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("College.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", edu_institution[college_count].name);
        fscanf(fp, "%s\n", edu_institution[college_count].type);
        fscanf(fp, "%s\n", edu_institution[college_count].location);
        fscanf(fp, "%d\n", &edu_institution[college_count].no_of_students);
        fscanf(fp, "%d\n", &edu_institution[college_count].no_of_professors);
        fscanf(fp, "%d\n", &edu_institution[college_count].rating);
        fscanf(fp, "%lf\n", &edu_institution[college_count].fee_structure);

        // update restuarant_count after adding a restaurant in the city
        college_count++;
    }
    fclose(fp);
}

/*
    Function : add_shops
    Description : adds an shop_count of required properties to the city
*/
void add_shops()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Shops.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", store[shop_count].name);
        fscanf(fp, "%s\n", store[shop_count].type);
        fscanf(fp, "%s\n", store[shop_count].location);

        // update shop_count after adding a shop in the city
        shop_count++;
    }
    fclose(fp);
}

/*
    Function : add_restuarants
    Description : adds an restuarant_count of required properties to the city
*/

void add_restuarants()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Restaurant.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", hotels[restaurant_count].name);
        fscanf(fp, "%d\n", &hotels[restaurant_count].no_of_workers);
        fscanf(fp, "%s\n", hotels[restaurant_count].type);
        fscanf(fp, "%d\n", &hotels[restaurant_count].working_hours);
        fscanf(fp, "%d\n", &hotels[restaurant_count].rating);
        fscanf(fp, "%s\n", hotels[restaurant_count].location);

        // update restuarant_count after adding a restaurant in the city
        restaurant_count++;
    }
    fclose(fp);
}

/*
    Function : add_police_station
    Description : adds an police_station of required properties to the city
*/
void add_police_station()
{
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Police_station.txt", "r");

    // if file is not found in the folder
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", stations[police_station_count].station_name);
        fscanf(fp, "%s\n", stations[police_station_count].location);
        fscanf(fp, "%d\n", &stations[police_station_count].no_of_constables);
        fscanf(fp, "%s\n", &stations[police_station_count].no_of_inspectors);
        fscanf(fp, "%d\n", &stations[police_station_count].no_of_cells);
        fscanf(fp, "%d\n", &stations[police_station_count].max_criminals);

        // update police_station_count after adding a police station in the city
        police_station_count++;
    }
    fclose(fp);
}
/*
    Function : add_nodes
    Description :
*/
void add_nodes()
{
    FILE *fp;

    fp=fopen("NodesNames.txt","r");

    //Check if the file exists
    if (fp == NULL)
    {
        cflag = 1;
        return;
    }

    while (!feof(fp))
    {
        fscanf(fp,"%s\n",Node_Names[node_count].nodes_name);
        node_count++;
    }
    fclose(fp);
}

/*
    Function : print_houses
    Description : Prints the details of all the houses in the city
*/
void print_houses()
{
    printf("\n----------------------------------------------------\n");
    int i;
    if (house_count == 0)
    {
        printf("There are no houses in the city\n");
        return;
    }
    for (i = 0; i < house_count; i++)
    {
        printf("House name : %s\n", home[i].house_name);
        printf("House number : %d\n", home[i].house_number);
        printf("Number of people in house : %d\n", home[i].house_people);
        printf("House location : %s\n", home[i].house_location);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function : print_school
    Description : Prints details of the schools in the city
*/
void print_school()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < school_count; i++)
    {
        printf("School name : %s\n", skool[i].school_name);
        printf("working hours : %d\n", skool[i].school_working_hours);
        printf("phone_number : %lld\n", skool[i].contact_no);
        printf("school location : %s\n", skool[i].school_location);
        printf("school rating : %d\n", skool[i].school_rating);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function : print_hospital
    Description : Prints details of the hospitals in the city
*/
void print_hospital()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < hospital_count; i++)
    {
        printf("Hospital name : %s\n", hosp[i].hospital_name);
        printf("Hospital location : %s\n", hosp[i].hospital_location);
        printf("Hospital rating : %d\n", hosp[i].hospital_rating);
        printf("Type of hospital: %s\n", hosp[i].hospital_type);
        printf("Number of doctors : %d\n", hosp[i].num_of_doctors);
        printf("Phone_number of hospital: %lld\n", hosp[i].contact_no);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function : print_office
    Description : Prints details of the offices in the city
*/
void print_office()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < office_count; i++)
    {
        printf("Office name : %s\n", off[i].office_name);
        printf("Number of emplyees : %d\n", off[i].num_of_employees);
        printf("Type of office: %s\n", off[i].office_type);
        printf("Office location : %s\n", off[i].office_location);
        printf("Working hours of the office : %d\n", off[i].working_hours);
        printf("Contact number of the office: %lld\n", off[i].contact_no);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function : print_busstand
    Description : Prints details of the busstand in the city
*/
void print_busstand()
{
    printf("\n----------------------------------------------------\n");
    int i;
    printf("busstand name : %s\n", cb.busstand_name);
    printf("busstand location : %s\n", cb.busstand_location);
    for (i = 0; i < bus_count; i++)
    {
        printf("number of buses : %d\n", buses[i].bus_num);
    }
    printf("\n----------------------------------------------------\n");
}

/*
    Function : print_bus
    Description : Prints details of the bus in the city
*/
void print_bus()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < bus_count; i++)
    {
        printf("Number of bus: %d\n", buses[i].bus_num);
        printf("Start: %s\n", buses[i].from);
        printf("Destination: %s\n", buses[i].to);
        printf("Number of stops: %d\n", buses[i].num_of_stops);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function : print_market
    Description : Prints details of the market in the city
*/
void print_market()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for(i=0; i<market_count; i++)
    {
        printf("market name : %s\n", m.market_name);
        printf("market location : %s\n", m.market_location);
        printf("market open time : %f\n", m.open_time);
        printf("market close time : %f\n", m.close_time);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function :print_industry
    Description : Prints details of the industries in the city
*/
void print_industry()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < industry_count; i++)
    {
        printf("Name of the industry:%s\n", industries[i].industry_name);
        printf("Location:%s\n", industries[i].location);
        printf("Number of industry:%d\n", industries[i].industry_no);
        printf("Industry Type:%s\n", industries[i].industry_type);
        printf("Number of workers:%d\n", industries[i].no_of_employees);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function :print_police_station
    Description : Prints details of the police stations in the city
*/
void print_police_station()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < police_station_count; i++)
    {
        printf("Name of station:%s\n", stations[i].station_name);
        printf("Location:%s\n", stations[i].location);
        printf("Number of constables in the police station:%d\n", stations[i].no_of_constables);
        printf("Number of inspectors in the police station%d\n", stations[i].no_of_inspectors);
        printf("Number of cells in the police station%d\n", stations[i].no_of_cells);
        printf("Number of people the cells can hold:%d\n", stations[i].max_criminals);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function :print_garden
    Description : Prints details of the gardens in the city
*/
void print_garden()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < garden_count; i++)
    {
        printf("Name of garden:%s\n", parks[i].garden_name);
        printf("Location:%s\n", parks[i].location);
        printf("Area:%lf\n", parks[i].area);
        printf("Start time of the garden:%s\n", parks[i].start_time);
        printf("Closing time of the garden:%s\n", parks[i].close_time);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function :print_restuarants
    Description : Prints details of the restuarants in the city
*/
void print_restuarants()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < garden_count; i++)
    {
        printf("%s\n", hotels[i].name);
        printf("%d\n", hotels[i].no_of_workers);
        printf("%s\n", hotels[i].type);
        printf("%d\n", hotels[i].working_hours);
        printf("%d\n", hotels[i].rating);
        printf("%s\n", hotels[i].location);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function : print_college
    Description : Prints details of the colleges in the city
*/
void print_college()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < college_count; i++)
    {
        printf("Name of the college:%s\n", edu_institution[i].name);
        printf("College type:%s\n", edu_institution[i].type);
        printf("Location:%s\n", edu_institution[i].location);
        printf("Number of students:%d\n", edu_institution[i].no_of_students);
        printf("Number of professors:%d\n", edu_institution[i].no_of_professors);
        printf("Rating:%d\n", edu_institution[i].rating);
        printf("Fees:%lf\n", edu_institution[i].fee_structure);
        printf("\n----------------------------------------------------\n");
    }

}

/*
    Function :print_shops
    Description : Prints details of the shops in the city
*/
void print_shops()
{
    printf("\n----------------------------------------------------\n");
    int i;
    for (i = 0; i < shop_count; i++)
    {
        printf("Name of the shop:%s\n", store[i].name);
        printf("Shop type:%s\n", store[i].type);
        printf("Location:%s\n", store[i].location);
        printf("\n----------------------------------------------------\n");

    }
}
/*

    Function : floyd
    Description : A person wants to travel around the
                  city and wants to know the efficient way
                  i.e shortest path to traverse in the city
*/
void check_floyd()
{
    int matrix[20][20];
    int x,y,w;
    int i,j;
    int n = 12;
    char choice;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            matrix[i][j] = MAX;
    }

    FILE *fp;

    fp = fopen("Floyd.txt","r");

    if(fp == NULL)
    {
        perror("File not found\n");
        exit(0);
    }

    while(!(feof(fp)))
    {
        fscanf(fp,"%d %d %d",&x,&y,&w);
        matrix[x][y] = w;
    }

    floyd(matrix,n);

    printf("Do you want to print result considering source as house?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 0;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }
    printf("\n");
    printf("Do you want to print result considering source as hospital?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 1;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as school?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 2;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Busstand?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 3;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Market?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 4;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Ploice_station?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 5;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as College?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 6;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Offices?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 7;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Gardens?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 8;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Restuarants?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 9;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Shops?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 10;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }

    printf("\n");
    printf("Do you want to print result considering source as Industries?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        int source = 11;
        for(i=0; i<n; i++)
        {
            if(i!=source)
                printf("%s to %s is %d units\n",Node_Names[source].nodes_name, Node_Names[i].nodes_name, matrix[source][i]);
        }

    }


    fclose(fp);
}

int min(int a, int b)
{
    if( a < b)
        return a;
    else
        return b;
}

void floyd(int matrix[20][20], int n)
{
    int i,j,k;
    for(k = 0; k < n ; k++)
    {
        for(i = 0; i < n ; i++)
        {
            for(j = 0; j < n; j++)
                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
        }
    }
}


/*
    Function : add_restaurants
    Description : Sorts the restaurants according to the
                  rating assigned to them, helps as a guide
                  for selecting the restaurant for dinner(?)
*/
void sort_restaurants()
{
    int i, j;
    char choice;
    struct restaurants temp;
    for (i = 1; i < restaurant_count; i++)
    {
        temp = hotels[i];
        j = i - 1;
        while (j >= 0 && hotels[j].rating > temp.rating)
        {
            hotels[j + 1] = hotels[j];
            j--;
        }
        hotels[j + 1] = temp;
    }

    // print restaurant after sorting
    printf("Do you want to print the sorted list?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
        print_restuarants();
}

/*
    Function : sort_industries
    Description : Sorts the number of employees
                  using quick sort to help in assigning
                  funds and other stuff
*/
void sort_industries()
{
    char choice;
    quickSort(industries, 0, industry_count - 1);
    printf("Do you want to print the sorted list?(Y/N)");
    scanf("%*c%c",&choice);
    if(choice == 'Y' || choice == 'y')
        print_restuarants();
}

void swap(struct industry a, struct industry b)
{
    struct industry temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(struct industry industries[], int low, int high)
{
    int pivot = industries[high].no_of_employees;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (industries[j].no_of_employees < pivot)
        {
            i++;
            swap(industries[i], industries[j]);
        }
    }
    swap(industries[i + 1], industries[high]);
    return (i + 1);
}

void quickSort(struct industry industries[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(industries, low, high);

        quickSort(industries, low, pi - 1);
        quickSort(industries, pi + 1, high);
    }
}

/*
    Function : hashing
    Description :
*/
void hashing()
{
    int i,j;
    for(i=0; i<house_count; i++)
    {
        hash[i].flag=0;
    }
    for(i=0; i<house_count; i++)
    {
        j=hashpassword(home[i].house_password);
        if(hash[i].flag==0)
        {
            strcpy(hash[j].password,home[i].house_password);
            hash[j].flag=1;
            array[i]=&hash[j];
        }
        else
        {
            strcpy(hash[j+1].password,home[i].house_password);
            hash[j+1].flag=1;
            array[i]=&hash[j];
        }
    }
    for(i=0; i<house_count; i++)
        printf("%p ",array[i]);
}

int hashpassword(char str[20])
{
    int i;
    int hasshhh=0;
    for(i=0; str[i]; i++)
    {
        int b=str[i];
        hasshhh=b+hasshhh;
    }
    return hasshhh%1000;
}

/*
   Function : Flood evacuation
   Description :
*/
void flood_evacuation()
{
    int u,v,w;
    int visited[12]= {0};
    FILE *fp;

    // open the file by searching in the folder
    fp = fopen("Flood.txt", "r");

    // if file is not found
    if (fp == NULL)
    {
        perror("File not found\n");
        return;
    }

    while (!feof(fp))
    {
        fscanf(fp,"%d %d %d\n",&u,&v,&w);
        flood_matrix[u][v]=w;
        flood_matrix[v][u]=w;
    }

    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
            printf("%d ",flood_matrix[i][j]);

        printf("\n");
    }
    int source=0;
    printf("\n");
    printf("%s-->",Node_Names[source].nodes_name);
    dfs(flood_matrix,12,source,visited);
}

void dfs(int flood_matrix[12][12],int n,int source,int visited[12])
{
    int i;
    visited[source]=1;

    for(i=0; i<n; i++)
    {
        if(flood_matrix[source][i]==1 && visited[i]==0)
        {
            printf("%s-->",Node_Names[i].nodes_name);
            dfs(flood_matrix,n,i,visited);
        }
    }
}

/*
    Function : detect cycles
    Description :
*/

void marathon()
{
    int u,v,w;
    FILE * fp;
    // open the file by searching in the folder
    fp = fopen("Flood.txt", "r");

    // if file is not found
    if (fp == NULL)
    {
        perror("File not found\n");
        return;
    }

    while (!feof(fp))
    {
        fscanf(fp,"%d %d %d\n",&u,&v,&w);
        cost_matrix[u][v]=w;
        cost_matrix[v][u]=w;
    }
    fclose(fp);

    // remove comments to print the matrix

    /*for(int i=0;i<12;i++)
    {
       for(int j=0;j<12;j++)
        printf("%d ",cost_matrix[i][j]);

       printf("\n");
    }*/
    bfs(cost_matrix,V,source,visited);
}

void bfs(int cost_matrix[V][V],int n,int source, int visited[V])
{
    for(int i=0; i<n; i++)
        visited[i]=-1;
    int queue[V];
    int front=0,rear=0;
    int u,i;
    queue[rear]=source;
    visited[source]=0;

    printf("The bfs traversal begins\n");
    while(front<=rear)
    {
        u=queue[front];
        // printf("%d\t",u);
        printf("%s ->",Node_Names[u].nodes_name);
        visited[u]=1;
        front=front+1;

        for(i=0; i<n; i++)
        {

            if(cost_matrix[u][i]==1 && visited[i]==-1)
            {
                rear=rear+1;
                queue[rear]=i;
                visited[i]=0;
            }
            else if(cost_matrix[u][i]==1 && visited[i]==0)
            {
                c++;
            }
        }
    }
    printf("\n");
    printf("The total number of cycles in the city :%d\n",c);
}

void search()
{
    int i,check;
    int flag = 1;
    char search[20];
    printf("Enter house to be searched\n");
    scanf("%s",search);
    for(i = 0; i < house_count ; i++)
    {
        check = search_house(home[i].house_name, search);
        if(check == 1)
        {
            flag = 0;
            printf("\nHouse is in the locality\n");
            return ;
        }
    }
    if(flag == 1)
        printf("\nHouse not found\n");
}

int search_house(char text[], char pattern[])
{
    int i,j,c;
    char ch1, ch2;
    int p = strlen(pattern);
    int q = strlen(text);
    for(i = 0; i <= q - p ; i++)
    {
        c = 0;
        for(j=0; j<=p; j++)
        {
            ch1 = tolower(pattern[j]);
            ch2 = tolower(text[i+j]);

            if(ch1 == ch2)
            {
                c++;
                if(c == p)
                    return 1;
            }
        }

        j = 0;
        while(j<p && pattern[j] == text[i+j])
        {
            j++;
            if(j == p)
                return 1;
        }
    }
    return 0;
}

/*
    Function : kruskals
    Description :
*/
void kruskals()
{
    FILE *fp;
    int i;
    int arr[V];

    fp = fopen("Kruskals.txt","r");
    if(fp == NULL)
    {
        perror("File not found\n");
        return ;
    }

    while(!feof(fp))
    {
        fscanf(fp,"%d %d %d", &s[graph_count].u, &s[graph_count].v, &s[graph_count].w);
        graph_count++;
    }

    for(i=0; i<V; i++)
        arr[i] = i;

    sort(s,graph_count);

    int sum = kruskals_sum(s,arr,graph_count,V);

    printf("Weight of minimum spanning tree is %d",sum);
}

void sort(struct graph s[], int n)
{
    int i,j;
    struct graph temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(s[j].w > s[j+1].w)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int find(int a[], int u, int v)
{
    if(a[u] == a[v])
        return 1;
    else
        return 0;
}

void union1(int a[], int n, int u, int v)
{
    int i,temp;
    temp = a[u];
    for(i=0; i<V; i++)
    {
        if(a[i] == temp)
            a[i] = a[v];
    }

}

int kruskals_sum(struct graph s[], int a[], int n, int v)
{
    int x,y,p;
    int sum = 0;
    int i,j;
    for(i=0; i<14; i++)
    {
        x = s[i].u;
        y = s[i].v;

        if((find(a, x, y)) == 0)
        {
            union1(a,n,x,y);
            sum = sum + s[i].w;
            //printf("sum is %d\n",sum);
        }
    }

    return sum;
}

void BST()
{
    TREE *root=NULL;
    // Adds the college data into the node
    for(int i=0; i<college_count; i++)
        root=insert_into_bst(root,edu_institution[i]);


    if(root==NULL)
    {
        printf("empty tree\n");
    }
    else
    {
        printf("-----------Inorder Traversal is:---------------------------------\n\n");
        //Inorder traversal of the created BST
        inorder(root);
        //Preorder traversal of the created BST
        printf("-----------Preorder Traversal is:--------------------------------\n\n");
        preorder(root);
        //Postorder traversal of the created BST
        printf("-----------Postorder Traversal is:--------------------------------\n\n");
        postorder(root);
    }

}

TREE * insert_into_bst(TREE *root,struct college data)
{
    TREE *newnode;
    newnode=(TREE *)malloc(sizeof(TREE));

    if(newnode==NULL)
    {
        printf("Memory full\n");
        return root;//do not return NULL
    }

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        printf("Root created\n");
        root=newnode;
        return newnode;
    }
    TREE *cur=root;
    TREE *parent=NULL;
    while(cur!=NULL)
    {
        parent=cur;
        if(newnode->data.rating <cur->data.rating)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if(newnode->data.rating < parent->data.rating)
        parent->left=newnode;
    else
        parent->right=newnode;

    return root;
}

void inorder(TREE *root)
{
    if(root!=NULL)//do not put while
    {
        inorder(root->left);
        printf("Name of the college:%s\n",root->data.name);
        printf("College type:%s\n", root->data.type);
        printf("Location:%s\n", root->data.location);
        printf("Number of students:%d\n", root->data.no_of_students);
        printf("Number of professors:%d\n",root->data.no_of_professors);
        printf("Rating:%d\n",root->data.rating);
        printf("Fees:%lf\n\n",root->data.fee_structure);
        inorder(root->right);
    }

}

void preorder(TREE *root)
{

    if(root!=NULL)//do not put while
    {
        printf("Name of the college:%s\n",root->data.name);
        printf("College type:%s\n", root->data.type);
        printf("Location:%s\n", root->data.location);
        printf("Number of students:%d\n", root->data.no_of_students);
        printf("Number of professors:%d\n",root->data.no_of_professors);
        printf("Rating:%d\n",root->data.rating);
        printf("Fees:%lf\n\n",root->data.fee_structure);
        preorder(root->left);
        preorder(root->right);
    }

}

void postorder(TREE *root)
{
    if(root!=NULL)//do not put while
    {

        postorder(root->left);
        postorder(root->right);
        printf("Name of the college:%s\n",root->data.name);
        printf("College type:%s\n", root->data.type);
        printf("Location:%s\n", root->data.location);
        printf("Number of students:%d\n", root->data.no_of_students);
        printf("Number of professors:%d\n",root->data.no_of_professors);
        printf("Rating:%d\n",root->data.rating);
        printf("Fees:%lf\n\n",root->data.fee_structure);
    }

}

void Dijkstras()
{
    int u,v,w,i,j,pos;
    int shortest[V];
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
        {
            if(i==j)
                cost_matrix[i][j]=0;
            else
                cost_matrix[i][j]=99999;
        }

    }
    FILE *fp;
    // open the file by searching in the folder
    fp = fopen("Floyd.txt", "r");

    // if file is not found
    if (fp == NULL)
    {
        perror("File not found\n");
        return;
    }
    else
        printf("File read succesfully\n");

    // read file till the end while storing the data in appropriate data types
    while (!feof(fp))
    {
        fscanf(fp, "%d%d%d\n", &u,&v,&w);
        cost_matrix[u][v]=w;
        cost_matrix[v][u]=w;

    }
    fclose(fp);
    for( i=0; i<V; i++)
    {
        dist[i]=cost_matrix[source][i];
    }
    for( i=0; i<V; i++)
    {
        path[i]=source;
    }
    visited[source]=1;
    int k;
    for(k=1; k<V; k++)
    {
        int mindistance=INT_MAX;
        for(i=0; i<V; i++)
        {
            if(dist[i]<mindistance && !visited[i])
            {
                mindistance=dist[i];
                pos=i;
            }
        }
        visited[pos]=1;
        for(j=0; j<V; j++)
        {
            if(dist[j]>(cost_matrix[pos][j]+mindistance) && !visited[j])
            {
                dist[j]=cost_matrix[pos][j]+mindistance;
                path[j]=pos;
            }
        }
    }
    printf("The distance array is\n");
    for(i=1; i<V; i++)
    {
        printf("%d to %d is %d\n",0,i,dist[i]);

    }
}
