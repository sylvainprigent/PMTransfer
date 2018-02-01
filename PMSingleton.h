#pragma once

#include <QtCore>

/// \class PMSingleton
/// \brief templated singleton patern that can be applied to any class
template <typename T>
class PMSingleton
{
protected:
    /// \fn PMSingleton();
    /// \brief Constructor
    PMSingleton(){}
    /// \fn ~PMSingleton();
    /// \brief Destructor
    ~PMSingleton(){}

public:
    // Publique interace
    /// \brief Instanciate the singleton
    /// \return an instance of the templated class
    static T *instance ()  {
        if (m_singleton == NULL)
        {
            //std::cout << "creating singleton." << std::endl;
            m_singleton = new T;
        }
        else
        {
            //std::cout << "singleton already created!" << std::endl;
        }

        return (static_cast<T*> (m_singleton));
    }

    /// \brief free the instance of the class
    static void kill(){
      if (NULL != m_singleton)
        {
          delete m_singleton;
          m_singleton = NULL;
        }
    }

private:
    static T *m_singleton; ///< Unique instance
};

template <typename T>
T *PMSingleton<T>::m_singleton = NULL;
