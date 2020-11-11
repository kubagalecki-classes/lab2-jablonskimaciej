#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    ResourceManager() //:
    /* stwórz na stercie, przypisz wsk. do r */
    {
      r = new Resource;
    }

    ~ResourceManager() {delete r;}

    ResourceManager(const ResourceManager& rm)
    /* : stwórz nowy obiekt, będący kopią *(rm.r) i przypisz jego adres do r */
    {
      r = new Resource{*rm.r};
    }

    ResourceManager& operator=(const ResourceManager& rm)
    {
      /* sprawdź, czy &rm i this to nie to samo, jeśli tak, nie rób nic */
      /* zwolnij bieżący zasób, na który wskazuje r
      : stwórz nowy obiekt, będący kopią *(rm.r) i przypisz jego adres do r */
      if (this != &rm) {
            delete r;
            r = new Resource{*rm.r};
        }
      return *this;
    }

    ResourceManager(ResourceManager&& rm)
    {
      r = rm.r;
      rm.r = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& rm)
    {
      if (this != &rm) {
        delete r;
        r = rm.r;
        rm.r = nullptr;
        return *this;
      }
    }

    double get() {return r->get();}

    private:
    Resource* r;
};
