namespace Monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{
    // We use [[maybe_unused]] to avoid warnings about unused variables
    // You could also output the monster instead
    [[maybe_unused]] Monster::MonsterType monster{ Monster::troll };

    return 0;
}
