#include "config.h"

using namespace std;

// Constructors and Destructors implemented in the header.
// Using Singleton's for configuration implementation as it seems ideal for this situation.
// Providing an access point for the Hashmap I intend to create.
// This will also make it easier to access and update the config information.

// Singleton's implementation
Config* Config::instance = 0;

Config* Config::getInstance()
{
    if(instance == 0)
        instance = new Config();
    return instance;
}


/*             Configuratiion Methods             */
// Sets the directory path for config


void Config::setAbsolutePath(string file)
{
    filename = file;
}


// Gets the directory path for config
string Config::getAbsolutePath()
{
    return filename;
}


// Checks to see if config exists
void Config::open()
{
    if(!config_file.is_open())
        config_file.open(filename.c_str(), fstream::in | fstream::out);
}

// loads information
void Config::load()
{
    string line;
    string key;
    string value;

    open();

    if(config_file.is_open())
    {
        while(getline(config_file, line))
        {
            size_t position = line.find("=");
            if(position > 0)
            {
                key = line.substr(0, position);
                value = line.substr(position+1, line.length()-1);
                keys.push_back(key);
                config_map[key] = value;
            }
        }
    }
    close();
}

void Config::changeFile(string file)
{
    close();
    config_map.clear();
    keys.clear();
    filename = file;
    open();
}

void Config::save()
{
    open();
    if(config_file.is_open())
    {
        for(unsigned i = 0; i < keys.size(); i++)
        {
            config_file << keys[i] << "=" << config_map[keys[i]] << endl;
        }
    }
    close();
}

// Gets value from hashmaps or throws exception
string Config::getValue(string key)
{
    if (config_map.end() == config_map.find(key)){
        throw "Key \"" + key + "\" was not given in config file!";
    }
    return config_map[key];
}

// Sets value in Hashmaps
void Config::setValue(string key, string value)
{
    config_map[key] = value;
}

// Closes config
void Config::close()
{
    if(config_file.is_open())
        config_file.close();
}

// Close config and deletes instance
void Config::destroy()
{
    close();
    delete instance;
}

// Validation for Integers returns false to throw error
bool Config::validateInt(const string input) {
    // The number of negative signs in string
    int negative_count =count(input.begin(), input.end(), '-');
    // if only '-'
    if((signed int) input.size() == negative_count) return false;
    // if '---1'
    else if (negative_count > 1) return false;
    //if negative sign is in wrong place
    else if (negative_count == 1 && input[0] != '-') return false;
    // The string contains a character that isn't within "-0123456789"
    else if (strspn(input.c_str(), "-0123456789") != input.size()) return false;
    return true;
}

// Command to retreive intergers
int Config::getNumber(string key) {
    string value = getValue(key);

    if (validateInt(value)) {
        return (int) strtod(value.c_str(), NULL);
    } else throw "The value for key: \"" + key + "\" should be a number. ";
}

vector<string> Config::getCommands(string key) {
    string value = getValue(key);
    vector<string> array;
    stringstream ss(value);
    string tmp;

    while (getline(ss,tmp,',')) {
        for (auto & c: tmp) c = toupper(c);
        // transform string to upper case
        array.push_back(tmp);
    }
    return array;
}
