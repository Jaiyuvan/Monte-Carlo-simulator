
#include"csv_parser.hpp"
#include"benchmark.hpp"
#include<algorithm>

//void field_scaner()
std::vector<StockData> parser(std::ifstream& csv_file)
{
    std::string line;

    // Skip header
    std::getline(csv_file, line);

    std::vector<StockData> annual_market_data;
    //Parse each line
    {
    struct Timer time;
    while (std::getline(csv_file, line))
    {
        StockData stockInfo{};
        //create start and end pointer
        const char* ptr = line.data();
        const char* end = ptr + line.size();

        int column = 0;
        bool valid_row = true;
        bool quoted_field=false;
        while (ptr < end)
        {
            const char* comma = ptr;
            while (comma<end){
                //To find skip comma in quoted field
                if ((*comma)=='"'){
                    quoted_field=!quoted_field;
                }
                if ((*comma)==','&& !quoted_field){
                     break;
                }
                ++comma;
            }
            std::string_view field(ptr,comma-ptr);
            switch (column)
            {
                case 0:
                    stockInfo.date.assign(field);
                    break;

                case 1:
                    stockInfo.ticker.append(field);
                    break;

                case 2:
                {
                    auto [p, ec] = std::from_chars(
                        field.data(),
                        field.data() + field.size(),
                        stockInfo.open
                    );

                    if (ec != std::errc{} ||
                        p != field.data() + field.size())
                        valid_row = false;

                    break;
                }

                case 3:
                {
                    auto [p, ec] = std::from_chars(
                        field.data(),
                        field.data() + field.size(),
                        stockInfo.close
                    );

                    if (ec != std::errc{} ||
                        p != field.data() + field.size())
                        valid_row = false;
                    break;
                }

                case 4:
                {
                    auto [p, ec] = std::from_chars(
                        field.data(),
                        field.data() + field.size(),
                        stockInfo.high
                    );

                    if (ec != std::errc{} ||p != field.data() + field.size())
                        valid_row = false;
                    break;
                }

                case 5:
                {
                    auto [p, ec] = std::from_chars(
                        field.data(),
                        field.data() + field.size(),
                        stockInfo.low
                    );

                    if (ec != std::errc{} ||
                        p != field.data() + field.size())
                        valid_row = false;
                    break;
                }

                case 6:
                {
                    auto [p, ec] = std::from_chars(
                        field.data(),
                        field.data() + field.size(),
                        stockInfo.volume
                    );

                    if (ec != std::errc{} ||
                        p != field.data() + field.size())
                        valid_row = false;

                    break;
                }

                default:
                    valid_row = false;
                    break;
            }
            ++column;
            if (comma == end)
                break;

            ptr = comma + 1;
        }

        if (valid_row && column == 7)
            annual_market_data.push_back(std::move(stockInfo));
    }
}

    return annual_market_data;
}
