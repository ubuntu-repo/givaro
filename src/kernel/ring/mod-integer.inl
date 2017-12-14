// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/zpz/givzpzInt.inl,v $
// Copyright(c)'1994-2009 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: JG Dumas
// $Id: givzpzInt.inl,v 1.11 2011-02-02 17:16:43 briceboyer Exp $
// ==========================================================================
#ifndef __GIVARO_mod_integer_INL
#define __GIVARO_mod_integer_INL
// Description:

namespace Givaro {
    
    // ------------------------- Arithmetic functions

    inline typename Mod<Integer>::Element&
    Mod<Integer>::mul (Element& r, const Element& a, const Element& b) const
    {
        Integer::mul(r,a,b); 
        Integer::modin(r,_p); 
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::sub (Element& r, const Element& a, const Element& b) const
    {
        Integer::sub(r,a,b);
        if (sign(r) < 0) Integer::addin(r,_p); 
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::add (Element& r, const Element& a, const Element& b) const
    {
        Integer::add(r,a,b); 
        if (r >= p) Integer::subin(r,_p);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::neg (Element& r, const Element& a) const
    {
        if (isZero(a)) r=a; 
        else Integer::sub(r,_p,a);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::negin (Element& r) const
    {
        if (! isZero(r)) Integer::sub(r,_p,r); 
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::inv (Element& r, const Element& a) const
    {
        return ::Givaro::inv(r,a,_p);
    }

//    TMPL
//    inline bool this->Mod<Integer>::isUnit(const Element& a) const 
//    { 
//        Element d;
//        ::Givaro::gcd(d,a,_p); 
//        return isOne(d) || isMOne(d); 
//    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::div (Element& r, const Element& a, const Element& b) const
    {
        Element ib;
        inv(ib, b);
        mul(r, a, ib);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::mulin (Element& r, const Element& a) const
    {
        Integer::mulin(r,a); 
        Integer::modin(r,_p);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::divin (Element& r, const Element& a) const
    {
        Element ia;
        inv(ia, a);
        return mulin(r, ia);
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::addin (Element& r, const Element& a) const
    {
        Integer::addin(r,a);  
        if (r >= p) Integer::subin(r,_p);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::subin (Element& r, const Element& a) const
    {
        Integer::subin(r,a);
        if ( sign(r) < 0) Integer::addin(r,_p);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::invin (Element& r) const
    {
        Element t = r;
        return ::Givaro::inv(r,t,_p);
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::axpy (Element& r, const Element& a, const Element& b, const Element& c) const
    {
        Integer::axpy(r,a,b,c);
        Integer::modin(r,_p);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::axpyin (Element& r, const Element& a, const Element& b) const
    {
        Integer::axpyin(r,a,b);
        Integer::modin(r,_p);
        return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::axmy (Element& r, const Element& a, const Element& b, const Element& c) const
    {
        Integer::axmy(r,a,b,c);
        Integer::modin(r,_p); 
        return r;
    }

    // r = c - a*b
    inline typename Mod<Integer>::Element&
    Mod<Integer>::maxpy (Element& r, const Element& a, const Element& b, const Element& c) const
    {
        Element tmp = c;
        Integer::maxpy(r, a, b, c);
        Integer::modin(r, _p);
        return r;
    }
    // r -= a*b
    inline typename Mod<Integer>::Element&
    Mod<Integer>::maxpyin (Element& r, const Element& a, const Element& b) const
    {
        Integer::maxpyin(r,a,b);
        Integer::modin(r,_p);
        return r;
    }
    // r = a*b - r
    inline typename Mod<Integer>::Element&
    Mod<Integer>::axmyin (Element& r, const Element& a, const Element& b) const
    {
        maxpyin(r,a,b);
        return negin(r);
    }

    // --------------------
    // ----- Initialisation
    
    inline typename Mod<Integer>::Element&
    Mod<Integer>::init(Element& x) const
    {
        return x = this->zero;
    }

    // ------------
    // ----- Reduce

    inline typename Mod<Integer>::Element&
    Mod<Integer>::reduce(Element& r, const Element& a) const
    {
	r = a % _p;
	if (r < 0) r = r + _p;
	return r;
    }

    inline typename Mod<Integer>::Element&
    Mod<Integer>::reduce(Element& r) const
    {
	r %= _p;
	if (r < 0) r = r + _p;
	return r;
    }


} // namespace Givaro

#endif // __GIVARO_mod_integer_INL

