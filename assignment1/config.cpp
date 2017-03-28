#include "config.h"

using namespace std;

// Constructors and Destructors implemented in the header.
// Using Singleton's for configuration implementation as it seems ideal for this situation.
// Providing an access point for the Hashmap I intend to create.
// This will also make it easier to access and update the config information.

// Singleton's implementation
Config* Config::instance = 0;

Config* Config::get_instance()
{
    if(instance == 0)
        instance = new Config();
    return instance;
}


/*             Configuratiion Methods             */
// Sets the directory path for config


void Config::set_absolute_path(string file)
{
    filename = file;
}


// Gets the directory path for config
string Config::get_absolute_path()
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

void Config::change_file(string file)
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
            config_file << keys[i] << "=" << config_map[keys[i]];
        }
    }
    close();
}

string Config::get_value(string key)
{
    if (config_map.end() == config_map.find(key)){
        throw "Key \"" + key + "\" was not given in config file!";
    }
    return config_map[key];
}

void Config::set_value(string key, string value)
{
    config_map[key] = value;
}

void Config::close()
{
    if(config_file.is_open())
        config_file.close();
}

void Config::destroy()
{
    close();
    delete instance;
}


