/*
 * Copyright 2005 Vinzenz Feenstra - evilissimo@users.sourceforge.net
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef GUARD_DELEGATES_CONNECTION_HPP_INCLUDED
#define GUARD_DELEGATES_CONNECTION_HPP_INCLUDED 1
#include "../DelegateN/DelegateBase.hpp"
namespace DL
{
  /** \brief Class Connection takes values directly from create_delgate() 
    */
  class Connection
  {
  public:
    Connection() 
    : m_connected(false), m_enabled(true),m_signal(0)
    {}
    /** \brief Takes the return value of a create_delegate function and initializes 
      * the Connection class from it        
      */
    Connection( DelegateObj con ) 
    : m_connected(false), m_enabled(true),m_signal(0)
    {
      this->connect(con);
    }
    ~Connection() 
    {
      this->disconnect();
    }
    /** \brief enabling/disabling the connection
      * \param state if it is true, or unset it enables the connection, if it false disables it.
      */
    void enable(bool state = true)
    {
      this->m_enabled = state;
    }
    /**  \brief Returns true if the Connection is currently enabled.
      */
    bool is_enabled()
    {
      return m_enabled;
    }
    /** \brief Detaches the binding to the Funktor/Delegate and frees its memory
      */
    void disconnect()
    {
      if(this->m_signal)
        delete this->m_signal;
      this->m_signal = NULL;
      this->enable();
      this->m_connected=false;
    }
    /** \brief Connect to a new Functor/Delegate
      */
    void connect(DelegateObj signal)
    {
      this->disconnect();
      if(signal.get() == 0)
        return;
      this->m_signal = signal.release();   
      this->enable(false);
      this->m_connected = true;
    }
    /** \brief Emits the Signal
      */
    void emit()
    {
      if(!this->m_enabled)
        this->m_signal->Invoke();
    }
    private:
    Connection(Connection const & other){}
    Connection & operator=(Connection &){}
    DelegateBase *m_signal;
    bool m_connected;
    bool m_enabled;
  };
           
} // namespace DL
#endif // GUARD_DELEGATES_CONNECTION_HPP_INCLUDED
