
doForm:: Form->Int -> IO Form
doForm form n = do
    if (length (content form)) <= n
        then return form
        else do
            let value = ((content form) !! n)
            putStrLn( question value)
            let content = (answerContent value)
            printAnswers content 1 
            inputjar <- readLn
            let option = (inputjar ::Int)
            if option > (length content)
                then  doForm form n
                else do
                    content <- addStat content option
                    
                    doForm form (n+1)