#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap st("msitni");

        st.guardGate();
    }
    std::cout << "==============================================================\n";
    {
        ScavTrap st("m42");
        for (size_t i = 0; i < 10; i++)
            st.attack("msitni");
        for (size_t i = 0; i < 10; i++)
            st.takeDamage(10);
        st.beRepaired(10);
        st.attack("msitni");
    }
    return 0;
}