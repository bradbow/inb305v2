#pragma once
class IView: public IObserver, ISubject
{
public:
	
	virtual void intitialise() = 0;

};

