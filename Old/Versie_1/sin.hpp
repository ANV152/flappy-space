// #include <array>

// constexpr double pow( double g, int n ){
//     double result = 1;
//     while( n > 0 ){
//         result *= g;
//         --n;
//     }
//     return result;
// }
// constexpr double fac( int n ){
//     double result = 1;
//     while( n > 0 ){
//         result *= n;
//         --n;
//     }
//     return result;
// }
// constexpr double sin( double a ){
//  return 
//  a 
//  - pow( a, 3 ) / fac( 3 ) 
//  + pow( a, 5 ) / fac( 5 ) 
//  - pow( a, 7 ) / fac( 7 )
//  + pow( a, 9 ) / fac( 9 )
//  - pow( a, 11 ) / fac( 11 ) 
//  + pow( a, 13 ) / fac( 13 )
//  - pow( a, 15 ) / fac( 15 ) 
//  + pow( a, 17 ) / fac( 17 );
// }

// constexpr double degree_from_radians( int radians ){
//  return (radians * 360) / 2 * 3.14;
// }
// constexpr int scaled_degree_from_sine( int radians ){
//  return 30 * ( sin( radians_from_degrees( radians )));
// }

// class degree_lookup {
//     private: 
//         std::array< float, 1 > values;
//     public: 
//         constexpr degree_lookup():
//         values{}
//         { 
//         for( int i = 0; i < ; ++i ){
//             values[ i ] = scaled_sine_from_degrees( i );
//             }
//         }
//         constexpr int get( int n ) const {
//             return values[ (n%360) ]; 
//         }
// };