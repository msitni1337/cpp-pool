#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n================= Subject test =====================\n\n";
    {
        ScavTrap st("msitni");

        st.guardGate();
    }
    std::cout << "\n============ test for attack + repair ==============\n\n";
    {
        ScavTrap st("m42");
        for (size_t i = 0; i < 10; i++)
            st.attack("msitni");
        for (size_t i = 0; i < 10; i++)
            st.takeDamage(10);
        st.beRepaired(10);
        st.attack("msitni");
    }
    std::cout << "\n============= test for copy constructor ============\n\n";
    {
        ScavTrap st("m42");
        for (size_t i = 0; i < 10; i++)
            st.attack("msitni");
        for (size_t i = 0; i < 5; i++)
            st.takeDamage(10);
        ScavTrap st1(st);
        for (size_t i = 0; i < 5; i++)
            st1.takeDamage(10);
        st1.beRepaired(10);
        st1.attack("msitni");
    }
    return 0;
}