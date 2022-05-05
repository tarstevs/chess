skip -gfi /usr/include/c++/*/*/*
skip -gfi /usr/include/c++/*/*
skip -gfi /usr/include/c++/*

# Skip the Catch library functions  when stepping into
skip -rfu Catch
skip -rfu _catch_sr

# Skip everything from the std namespace
skip -rfu ^std::
skip -rfu ^gsl::
# Skip everything in SFML workspace
skip -rfu ^sf::
skip -rfu ^arma::
skip -rfu ^Glue
