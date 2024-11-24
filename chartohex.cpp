#include "chartohex.h"

CharToHex::CharToHex(QByteArray data) {

    char flag = 0;
    unsigned char change_data = 0;
    hex_data_length = 0;

    hex_data.resize(data.length());

    data = data.toHex();

    for(unsigned int  i = 0; i < data.length(); i++)
    {
         change_data <<= 4;

        if(flag == 2)
        {
            flag = 0;
            hex_data[hex_data_length]  = change_data;
            hex_data_length++;
        }

        if (data[hex_data_length] >= 'a' && data[hex_data_length] <= 'f')                  //ascii��ת��
        {
            change_data |= data[hex_data_length] - 87;
            flag++;
        }
        else if (data[hex_data_length] >= '0' && data[hex_data_length] <= '9')
        {
            change_data |= data[hex_data_length] - 48;
            flag++;

        }
        else if (data[hex_data_length] >= 'A' && data[hex_data_length] <= 'F')
        {
            change_data |= data[hex_data_length] - 55;
            flag++;
        }
        else if (data[hex_data_length] == ' ')
            continue;
        else
        {
            break;
        }

    }

    hex_data.resize(hex_data_length);
}
