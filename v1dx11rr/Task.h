class Task
{
public:
	Task()
	{
		MisionActual = 0;
		MisionCompletada = false;
	}
	
	void SetMision(int MisionActual)
	{
		this->MisionActual = MisionActual;
	}

	int GetMision()
	{
		return this->MisionActual;
	}

private:
	int MisionActual = 0;
	bool MisionCompletada = false;
};