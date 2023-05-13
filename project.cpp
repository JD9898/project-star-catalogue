#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include <set>

class observed_object
{
private:
    int number;
    std::string type;
public:
    observed_object():
        type{} {}
    observed_object(const std::string object_type):
        type{object_type} {}
    virtual ~observed_object(){}    
    virtual void info()=0; // pure virtual function
};

class galaxy: public observed_object 
{
    friend std::ostream & operator<<(std::ostream &os, const galaxy &star);
    friend std::istream & operator>>(std::istream &is, galaxy &star);
private:
    std::string name;
    std::string hubble_type;
    double redshift;
    double total_mass;
    double stellar_mass_fraction;
    // std::vector<galaxy> satellites;
public:
    galaxy():
        observed_object{"galaxy"}, name{""} {}
    galaxy(std::string galaxy_name, std::string hubble_type, double redshidt, double total_mass, double stellar_mass_fraction):
        observed_object{"galaxy"}, name{galaxy_name}, hubble_type{hubble_type}, redshift{redshift},
        total_mass{total_mass}, stellar_mass_fraction{stellar_mass_fraction} {}
    void set_name(std::string galaxy_name) {name = galaxy_name;}
    std::string get_name() {return name;}
    ~galaxy() {}
    void info() {std::cout<<""<<std::endl;}
};

class star: public observed_object 
{
    friend std::ostream & operator<<(std::ostream &os, const star &star);
    friend std::istream & operator>>(std::istream &is, star &star);
private:
    std::string name;
    std::string spectral_type;
public:
    star():
        observed_object{"star"}, name{""} {}
    star(std::string star_name, std::string star_spectral_type):
        observed_object{"star"}, name{star_name}, spectral_type{star_spectral_type} {}
    void set_name(std::string star_name) {name = star_name;}
    std::string get_name() {return name;}
    ~star() {}
    void info() {std::cout<<""<<std::endl;} 
};

class planet: public observed_object 
{
    friend std::ostream & operator<<(std::ostream &os, const planet &planet);
    friend std::istream & operator>>(std::istream &is, planet &planet);
private:
    std::string name;
public:
    planet():
        observed_object{"planet"}, name{""} {}
    planet(std::string planet_name):
        observed_object{"planet"}, name{planet_name} {}
    void set_name(std::string planet_name) {name = planet_name;}
    std::string get_name() {return name;}
    ~planet() {}
    void info() {std::cout<<""<<std::endl;} 
};

// Function to overload << operator
std::ostream & operator<<(std::ostream &os, const galaxy &galaxy_instance)
{
  os<<"galaxy name: "<<galaxy_instance.name<<"; hubble type: "<<galaxy_instance.hubble_type
  <<"; redshift: "<<galaxy_instance.redshift<<"; total mass: "<<galaxy_instance.total_mass
  <<"; stellar mass fraction: "<<galaxy_instance.stellar_mass_fraction<<std::endl;
  return os;
};

std::ostream & operator<<(std::ostream &os, const star &star_instance)
{
  os<<"star name: "<<star_instance.name<<"; spectral type: "<<star_instance.spectral_type<<std::endl;
  return os;
};

std::ostream & operator<<(std::ostream &os, const planet &planet_instance)
{
  os<<"planet name: "<<planet_instance.name<<std::endl;
  return os;
};

// input check
void input_check(double& input)
{
    while(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore();
    std::cout<<"Bad input, please input a number: "<<std::endl;
    std::cin>>input;
    }
}

void input_check(int& input)
{
    while(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore();
    std::cout<<"Bad input, please input a number: "<<std::endl;
    std::cin>>input;
    }
}

// Function to overload >> operator for reading input galaxy
std::istream & operator>>(std::istream &is, galaxy &gal)
{
    std::string name{gal.name};
    std::string hubble_type{gal.hubble_type};
    double redshift{gal.redshift};
    double total_mass{gal.total_mass};
    double stellar_mass_fraction{gal.stellar_mass_fraction};

    std::cout<<"please input galaxy name:"<<std::endl;
    is>>gal.name;
    std::cout<<"please input galaxy hubble type:"<<std::endl;
    is>>gal.hubble_type;
    std::cout<<"please input galaxy redshift:"<<std::endl;
    is>>gal.redshift;
    input_check(gal.redshift);
    std::cout<<"please input galaxy total mass:"<<std::endl;
    is>>gal.total_mass;
    input_check(gal.total_mass);
    std::cout<<"please input galaxy stellar mass fraction:"<<std::endl;
    is>>gal.stellar_mass_fraction;
    input_check(gal.stellar_mass_fraction);
  return is;
}

std::istream & operator>>(std::istream &is, star &star)
{
    std::string name{star.name};
    std::cout<<"please input star name:"<<std::endl;
    is>>star.name;
    std::cout<<"please input star spectral type:"<<std::endl;
    is>>star.spectral_type;   
  return is;
}

std::istream & operator>>(std::istream &is, planet &planet)
{
    std::string name{planet.name};
    std::cout<<"please input planet name:"<<std::endl;
    is>>planet.name;
  return is;

}

// functions to print out a vector
void print_vector(std::vector<galaxy> vector)
{
    std::vector<galaxy>::iterator vector_begin{vector.begin()};
    std::vector<galaxy>::iterator vector_end{vector.end()};
    std::vector<galaxy>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::cout<<*vector_iterator<<std::endl;
    }
}

void print_vector(std::vector<star> vector)
{
    std::vector<star>::iterator vector_begin{vector.begin()};
    std::vector<star>::iterator vector_end{vector.end()};
    std::vector<star>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::cout<<*vector_iterator<<std::endl;
    }
}

void print_vector(std::vector<planet> vector)
{
    std::vector<planet>::iterator vector_begin{vector.begin()};
    std::vector<planet>::iterator vector_end{vector.end()};
    std::vector<planet>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::cout<<*vector_iterator<<std::endl;
    }
}

void print_vector(std::vector<std::string> vector)
{
    std::vector<std::string>::iterator vector_begin{vector.begin()};
    std::vector<std::string>::iterator vector_end{vector.end()};
    std::vector<std::string>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::cout<<*vector_iterator<<std::endl;
    }
}

void copy_content_to_file(std::string input, std::string output)
{
    std::string line;
    std::ifstream ini_file{input}; 
    std::ofstream out_file{output};
    if (ini_file && out_file) {
        while (std::getline(ini_file, line)) {
            out_file << line << "\n";
        }
    }
    else {
        std::cout<<("Cannot read File")<<std::endl;
    }

    ini_file.close();
    out_file.close();
}

void append_file_to_file(std::string input, std::string output)
{
    std::ifstream ifile(input);
    std::ofstream ofile(output, std::ios::app);
    ofile << ifile.rdbuf();
}

void export_all_data_to_file(std::vector<galaxy> galaxies, std::vector<star> stars, std::vector<planet> planets, std::string file) 
{
    std::ofstream outdata; // outdata is like cin
    outdata.open(file); // opens the file
    if( !outdata ) { // file couldn't be opened
        std::cerr << "File can not be opened" << std::endl;
        exit(1);
    }

    std::vector<galaxy>::iterator vector_begin{galaxies.begin()};
    std::vector<galaxy>::iterator vector_end{galaxies.end()};
    std::vector<galaxy>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        outdata << *vector_iterator << std::endl;
    }

    std::vector<star>::iterator star_vector_begin{stars.begin()};
    std::vector<star>::iterator star_vector_end{stars.end()};
    std::vector<star>::iterator star_vector_iterator;
    for(star_vector_iterator=star_vector_begin; star_vector_iterator<star_vector_end; ++star_vector_iterator) {
        outdata << *star_vector_iterator << std::endl;
    }

    std::vector<planet>::iterator planet_vector_begin{planets.begin()};
    std::vector<planet>::iterator planet_vector_end{planets.end()};
    std::vector<planet>::iterator planet_vector_iterator;
    for(planet_vector_iterator=planet_vector_begin; planet_vector_iterator<planet_vector_end; ++planet_vector_iterator) {
        outdata << *planet_vector_iterator << std::endl;
    }

    outdata.close();
}

void refresh_db()
{
    copy_content_to_file("out.dat", "database.dat");
}

void clear_db()
{
    std::ofstream ofs;
    ofs.open("database.dat", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void export_data_to_file(std::vector<galaxy> vector) 
{
    std::ofstream outdata; // outdata is like cin
    outdata.open("out.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
        std::cerr << "File can not be opened" << std::endl;
        exit(1);
    }

    std::vector<galaxy>::iterator vector_begin{vector.begin()};
    std::vector<galaxy>::iterator vector_end{vector.end()};
    std::vector<galaxy>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        outdata << *vector_iterator << std::endl;
    }
    outdata.close();
}

void export_data_to_file(std::vector<star> vector) 
{
    std::ofstream outdata; // outdata is like cin
    outdata.open("out.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
        std::cerr << "File can not be opened" << std::endl;
        exit(1);
    }

    std::vector<star>::iterator vector_begin{vector.begin()};
    std::vector<star>::iterator vector_end{vector.end()};
    std::vector<star>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        outdata << *vector_iterator << std::endl;
    }
    outdata.close();
}

void export_data_to_file(std::vector<planet> vector) 
{
    std::ofstream outdata; // outdata is like cin
    outdata.open("out.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
        std::cerr << "File can not be opened" << std::endl;
        exit(1);
    }

    std::vector<planet>::iterator vector_begin{vector.begin()};
    std::vector<planet>::iterator vector_end{vector.end()};
    std::vector<planet>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        outdata << *vector_iterator << std::endl;
    }
    outdata.close();
}

void export_data_to_file(std::vector<std::string> vector) 
{
    std::ofstream outdata; // outdata is like cin
    outdata.open("out.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
        std::cerr << "File can not be opened" << std::endl;
        exit(1);
    }

    std::vector<std::string>::iterator vector_begin{vector.begin()};
    std::vector<std::string>::iterator vector_end{vector.end()};
    std::vector<std::string>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        outdata << *vector_iterator << std::endl;
    }
    outdata.close();
}

std::vector<std::string> search_for_object(std::string search_string)
{
    std::ifstream file_stream("database.dat");
    std::string line;
    std::vector<std::string> search_results;
    int count{0};
    while(getline(file_stream, line)) {
        if (line.find(search_string) != std::string::npos) {
            search_results.push_back(line);
            count++;
        }
    }
    std::cout<<"There are "<<count<<" matching results: "<<std::endl;
    print_vector(search_results);
    return search_results;
}

std::tuple<std::vector<galaxy>, std::vector<star>, std::vector<planet>> read_from_file_to_vectors(std::string data_file)
{
    std::string input_object_type;

    std::string observed_object_type;
    std::string observed_object_name;

    std::vector<galaxy> new_galaxy_vector;
    std::vector<star> new_star_vector;
    std::vector<planet> new_planet_vector;
    std::vector<std::string> observed_object_type_vector;
    std::vector<std::string> observed_object_name_vector;

    std::string line;

    // Open file and check if successful
    std::fstream data_stream(data_file);
    if (data_stream.fail()) {
        std::cout<<"File did not open successfully"<<std::endl;
    } else {
        std::cout<<"File opened successfully"<<std::endl;
    }

    // Read data from file
    while (std::getline(data_stream, line)) {
        std::stringstream input_stream(line);
        std::string temp{""};
        std::vector<std::string> words;
        while(std::getline(input_stream, temp, '|') && temp!=""){
            words.push_back(temp);
        }

        observed_object_type = words[0];
        observed_object_type_vector.push_back(observed_object_type);


        if (observed_object_type == "galaxy") {
            std::string name{words[1]};
            std::string hubble_type{words[2]};
            double redshift{std::stod(words[3])};
            double total_mass{std::stod(words[4])};
            double stellar_mass_fraction{std::stod(words[5])};
            galaxy new_galaxy(name,hubble_type,redshift,total_mass,stellar_mass_fraction);
            new_galaxy_vector.push_back(new_galaxy);
        } else if (observed_object_type == "star") {
            std::string name{words[1]};
            std::string spectral_type{words[2]};
            star new_star(name,spectral_type);
            new_star_vector.push_back(new_star);           
        } else if (observed_object_type == "planet") {
            std::string name{words[1]};
            planet new_planet(name);
            new_planet_vector.push_back(new_planet);           
        }
    }

    std::tuple<std::vector<galaxy>, std::vector<star>, std::vector<planet>> results (new_galaxy_vector, new_star_vector, new_planet_vector);
    return results;
}

void insert_new_entries_to_db(std::vector<galaxy> new_galaxy_vector, std::vector<star> new_star_vector, std::vector<planet> new_planet_vector)
{
    export_all_data_to_file(new_galaxy_vector,new_star_vector,new_planet_vector,"processing_data.dat");
    append_file_to_file("processing_data.dat", "database.dat");
}

void insert_to_db_vectors(std::vector<galaxy>& all_galaxies, std::vector<star>& all_stars, std::vector<planet>& all_planets,
std::vector<galaxy> new_galaxy_vector, std::vector<star> new_star_vector, std::vector<planet> new_planet_vector)
{
    std::vector<galaxy> galaxies_to_add;
    std::vector<star> stars_to_add;
    std::vector<planet> planets_to_add;
    bool object_found{0};

    for (galaxy g: new_galaxy_vector) {
        for (galaxy og: all_galaxies) {
            if(g.get_name() == og.get_name()) {
                object_found=1;
            }  
        }
        if (!object_found) {
            all_galaxies.push_back(g);
            galaxies_to_add.push_back(g);
            object_found=0;
        }
    }
    for (star s: new_star_vector) {
        for (star os: all_stars) {
            if (s.get_name() == os.get_name()) {
                object_found=1;
            } 
        }
        if (!object_found) {
            all_stars.push_back(s);
            stars_to_add.push_back(s);
            object_found=0;
        }    
    }   
    
    for (planet p: new_planet_vector) {
        for (planet op: all_planets) {
            if (p.get_name() == op.get_name()) {
                object_found=1;
            } 
        }
        if (!object_found) {
            all_planets.push_back(p);
            planets_to_add.push_back(p);
            object_found=0;
        }    
    }
    insert_new_entries_to_db(galaxies_to_add, stars_to_add, planets_to_add);
}

void import_multiple_files(std::vector<galaxy>& all_galaxies, std::vector<star>& all_stars, std::vector<planet>& all_planets) 
{
    std::string file_names;
    std::cout<<"Please first copy all .dat files in the directory where this program locates, then please input their name in such format: sample1.dat,sample2.dat"<<std::endl;
    std::cout<<"N.B.: Please do not include comma inside file names"<<std::endl;
    std::cin>>file_names;
    std::vector<std::string> files;
    std::stringstream ss(file_names);
    std::string substr;
    while(std::getline(ss, substr, ',') && substr!=""){
        files.push_back(substr);
    }

    std::vector<std::string>::iterator vector_begin{files.begin()};
    std::vector<std::string>::iterator vector_end{files.end()};
    std::vector<std::string>::iterator vector_iterator;
    for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator) {
        std::tuple<std::vector<galaxy>, std::vector<star>, std::vector<planet>> results_1 {read_from_file_to_vectors(*vector_iterator)};
        std::vector<galaxy> new_galaxy_vector_1{std::get<0>(results_1)};
        std::vector<star> new_star_vector_1{std::get<1>(results_1)};
        std::vector<planet> new_planet_vector_1{std::get<2>(results_1)};
        insert_to_db_vectors(all_galaxies, all_stars, all_planets, new_galaxy_vector_1, new_star_vector_1, new_planet_vector_1);
    }
}

void enter_new_object(std::vector<galaxy>& all_galaxies, std::vector<star>& all_stars, std::vector<planet>& all_planets)
{
    std::vector<galaxy> galaxies_to_add;
    std::vector<star> stars_to_add;
    std::vector<planet> planets_to_add;
    std::string input_object_type;
    // Ask user to enter input object type
    std::cout<<"Enter the object type you want to enter (galaxy, star, planet): ";
    std::cin>>input_object_type;

    if (input_object_type == "galaxy") {
        galaxy new_galaxy;
        std::cin>>new_galaxy;
        galaxies_to_add.push_back(new_galaxy);
        std::cout<<"Galaxy "<<new_galaxy<<" has been added to the database.";
    }

    if (input_object_type == "star") {
        star new_star;
        std::cin>>new_star;
        stars_to_add.push_back(new_star);
        std::cout<<"Star "<<new_star<<" has been added to the database.";
    }

    if (input_object_type == "planet") {
        planet new_planet;
        std::cin>>new_planet;
        planets_to_add.push_back(new_planet);
        std::cout<<"Planet "<<new_planet<<" has been added to the database.";
    }
    insert_to_db_vectors(all_galaxies, all_stars, all_planets, galaxies_to_add, stars_to_add, planets_to_add);
}

void delete_object()
{

}

int main ()
{
    std::vector<galaxy> all_galaxies;
    std::vector<star> all_stars;
    std::vector<planet> all_planets;

    int data_entries = 0;
    std::string line;

    std::string exit;
    int function;
    std::string search;

    std::tuple<std::vector<galaxy>, std::vector<star>, std::vector<planet>> results {read_from_file_to_vectors("initial_data.dat")};

    std::vector<galaxy> new_galaxy_vector{std::get<0>(results)};
    std::vector<star> new_star_vector{std::get<1>(results)};
    std::vector<planet> new_planet_vector{std::get<2>(results)};

    clear_db();
    insert_to_db_vectors(all_galaxies,all_stars,all_planets,new_galaxy_vector,new_star_vector,new_planet_vector);

    std::cout<<"Here are the initial objects in the database:"<<std::endl;
    print_vector(all_galaxies);
    print_vector(all_stars);
    print_vector(all_planets);

    std::cout<<"Now try enter some more objects into the database, now input a file name: "<<std::endl;
    std::cout<<"N.B. Default file is called data1.dat, if you want to import your own data, make sure they are in the same format."<<std::endl;
    std::string new_file;
    std::cin>>new_file;
    std::tuple<std::vector<galaxy>, std::vector<star>, std::vector<planet>> results_1 {read_from_file_to_vectors(new_file)};
    std::vector<galaxy> new_galaxy_vector_1{std::get<0>(results_1)};
    std::vector<star> new_star_vector_1{std::get<1>(results_1)};
    std::vector<planet> new_planet_vector_1{std::get<2>(results_1)};
    insert_to_db_vectors(all_galaxies,all_stars,all_planets,new_galaxy_vector_1,new_star_vector_1,new_planet_vector_1);
    std::cout<<"Now these objects in the input file have been added to database.dat. "<<std::endl;

    std::cout<<"Next let's explore some more features."<<std::endl;

    while(exit!="y") {
        std::cout<<"What do you want to do next? please select by entering the corresponding number:"<<std::endl;
        std::cout<<"1. Reset database"<<std::endl;
        std::cout<<"2. Filter data by type"<<std::endl;
        std::cout<<"3. Search for an object"<<std::endl;
        std::cout<<"4. Import data from one or multiple experiments, i.e. one or multiple files"<<std::endl;
        std::cout<<"5. Enter a new object to database"<<std::endl;
        std::cout<<"6. Delete an object from the database"<<std::endl;
        // std::cout<<". "<<std::endl;
        // std::cout<<". "<<std::endl;
        // std::cout<<". "<<std::endl;

        std::cin>>function;
        input_check(function);
        while (function < 1 || function >5) {
            std::cout<<"Please input a correct number: "<<std::endl;
            std::cin>>function;
        }

        if(function==1) { //reset db
            export_all_data_to_file(new_galaxy_vector, new_star_vector, new_planet_vector, "out.dat");
            refresh_db();
        } else if(function==2) { //filter objects by type
            int filter_type;
            std::cout<<"Choose an object: Enter 1 for galaxy, 2 for star and 3 for planet"<<std::endl;
            std::cin>>filter_type;
            input_check(filter_type);
            while (filter_type < 1 || filter_type >3) {
                std::cout<<"Please input a correct number: "<<std::endl;
                std::cin>>filter_type;
            }

            if(filter_type==1) {
                export_data_to_file(all_galaxies);
            } else if (filter_type==2) {
                export_data_to_file(all_stars);
            } else if (filter_type==3) {
                export_data_to_file(all_planets);
            }
            std::cout<<"Data has been saved to out.dat"<<std::endl;

        } else if(function==3) {
            std::string search;
            std::string save;
            std::cout<<"Please input keyword for searching: "<<std::endl;
            std::cin>>search;
            std::vector<std::string> search_results {search_for_object(search)};
            std::cout<<"Do you want to save these results into out.dat? press y to confirm, any other keys to skip"<<std::endl;
            std::cin>>save;
            if (save=="y") {
                export_data_to_file(search_results);
                std::cout <<"Search results have been saved to out.dat"<< std::endl;
            }
        } else if(function==4) {
            import_multiple_files(all_galaxies,all_stars,all_planets);
        } else if(function==5) {
            enter_new_object(all_galaxies,all_stars,all_planets);
        } else if(function==6) {
            delete_object();
        }
        else if(function==7) {
            
        }

        std::cout<<"Press y to exit the program, any other key to continue."<<std::endl;
        std::cin>>exit;
    }
    
}