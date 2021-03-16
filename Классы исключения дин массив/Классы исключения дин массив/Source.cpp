//#include <iostream>
//
//
//
//
//
//
//
//int arr[5] = { 0,1,2,3,4 };
//
//int getElem(int index)
//{
//    if (index >= 0 && index < 5)
//    {
//        return arr[index];
//    }
//    else
//    {
//        //std::cout << "under throw" << std::endl;  //  ++
//        throw std::out_of_range("Error! Incorrect index!");
//        //std::cout << "after throw" << std::endl;  //  --
//        //throw ("Error! Incorrect index!");
//    }
//}
//
//int division(int num1, int num2)
//{
//    if (num2 != 0)
//    {
//        return num1 / num2;
//    }
//    else
//    {
//        throw std::invalid_argument("Error! Second argument can't be zero!");
//    }
//}
//
//int main()
//{
//
//
//
//    try
//    {
//        int num1 = getElem(2);
//        std::cout << "num1 = " << num1 << std::endl;
//        int num2 = getElem(0);
//        std::cout << "num2 = " << num2 << std::endl;
//        int result = division(num1, num2);
//        std::cout << "result = " << result << std::endl;
//
//    }
//    
//    catch (const std::exception& ex)
//    {
//        //std::cout << "under what" << std::endl;  //++
//        std::cout << ex.what();
//        //std::cout << "after what"<< std::endl;   //++
//    }
//    //catch (std::out_of_range& ex)
//    //{
//    //    std::cout << "under what" << std::endl;  //++
//    //    std::cout << ex.what();
//    //    //std::cout << "after what"<< std::endl;   //++
//    //}
//    //catch (std::invalid_argument & ex)
//    //{
//    //    //std::cout << "under what" << std::endl;  //++
//    //    std::cout << ex.what();
//    //    //std::cout << "after what"<< std::endl;  //++
//    //}
//    //catch (...)
//    //{
//    //    std::cout << "Error";
//    //}
//
//
//}