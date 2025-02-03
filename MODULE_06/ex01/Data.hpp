#ifndef DATA_HPP
#define DATA_HPP

class Data {

	private:
		void *_content;
	
	public:
		Data();
		Data(const Data&);
		Data (void *content);
		Data& operator=(const Data&);
		~Data();
};

#endif