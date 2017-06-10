class CountA
{
	friend class SAHP;
private:
	int *ip;
	size_t size;
	CountA(int *p):ip(p),size(1){ }
	~CountA() {
		delete ip;
	}
};

class SAHP
{
public:
	SAHP(int *p, int va) :val_ptr(new CountA(p)), val(va) {
	}

	SAHP(const SAHP& obj) :val_ptr(obj.val_ptr), val(obj.val) {
		++val_ptr->size;
	}

	SAHP& operator=(const SAHP& eobj) {
		++eobj.val_ptr->size;
		if (--val_ptr->size==0) //���\��H�ۤv�ƻs���ۤv
			delete val_ptr;
		val_ptr = eobj.val_ptr;
	}
	~SAHP() {
			std::cout << val_ptr->size << std::endl;
			if (--val_ptr->size == 0)  //�P�_�O�_�٦���L�H�b�ϥ�
				delete val_ptr;
	};

	int *get_ptr() {
		return val_ptr->ip;
	}

	int get_int() {
		return val;
	}

	void set_ptr(int *v1) {
		val_ptr->ip = v1;
	}

	void set_int(int i) {
		val = i;
	}

	int get_ptr_val()const {
		return *val_ptr->ip;
	}

	void set_ptr_val(int val) {
		*val_ptr->ip = val;
	}

private:
	//int *val_ptr;
	int val;
	CountA *val_ptr;
	
};