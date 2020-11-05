module Main where
import Data.List()
import System.IO()
import System.Random (newStdGen, mkStdGen, randomR, randomRIO)
import System.Console.ANSI
--               Respuesta  cantidad de veces contestada
data Answer = Answer {text::String,stat:: Int}
--                   Pregunta  Respuestas tipo
data Question = Question { question ::String, answerContent :: [Answer]}
--                Preguntas Nombre
data Form = Form  {content :: [Question],name :: String,response:: Int} 

defaultAnswer = [ (Answer "Muy Malo" 0), (Answer "Malo" 0), (Answer "Regular" 0),(Answer "Bueno" 0),(Answer "Muy Bueno" 0) ]

main :: IO()
main = do
    let answer = Answer "No" 0
    let answer2 = Answer "Si" 0
    let question = Question "¿Estaría de acuerdo en apoyar el cobro de más impuestos para promover el levantamiento de la economía?" [answer2,answer]
    let question1 = Question "¿Como catalogaría el desempeño del gobierno en el manejo de la pandemia por COVID?" defaultAnswer
    let form = Form [question, question1] "Formulario Prueba" 0
    mainLoop [form]

mainLoop :: [Form] ->IO()
mainLoop a = do
    printMenu
    option <- getLine 
    if option == "1" --Crear Formulario
        then do
            clearScreen
            form <- makeForm
            mainLoop ( a ++ [form])
        else if option == "2"
            then  do 
                clearScreen 
                putStrLn"\n-- Formularios Disponibles --"
                showForms a 1
                inputjar <- readLn
                let option = (inputjar ::Int)
                let totalElements = length a
                if option > totalElements
                    then mainLoop a
                    else do 
                        putStrLn" \nContestar Automaticamente [y=Sí,n=no] (por defecto y)"
                        auto <- getLine
                        let element = a !! (option-1) --get form
                        if auto == "n" 
                            then do 
                                newForm <- (doForm element ) --do form a return form with stats
                                mainLoop (replaceAtIndex (option-1) newForm a)
                            else do
                                newForm <- (automaticForm element ) --do form a return form with stats
                                mainLoop (replaceAtIndex (option-1) newForm a)
                                
            else if option == "3" -- Estadisticas
                then do
                    clearScreen 
                    putStrLn"\n-- Estadisticas --"
                    putStrLn"1) Formularios contestados x veces"
                    putStrLn"2) Resultado de un formulario "
                    putStrLn"3) Formulario más contestado"
                    option <- getLine
                    if option == "1" 
                        then do 
                            putStrLn"Minimo:"
                            inputjar <- readLn
                            let option = (inputjar ::Int)
                            let forms = filter ( \x -> (response x) >= option ) a
                            clearScreen 
                            putStrLn " -- Formularios --"
                            showForms forms 1
                            putStrLn " \nPresione Cualquier letra para continuar"
                            getChar
                            mainLoop a
                        else if option == "2" 
                            then do
                                clearScreen 
                                putStrLn"\n-- Formularios Disponibles --"
                                showForms a 1
                                inputjar <- readLn
                                let option = (inputjar ::Int)
                                if option > (length a)
                                    then mainLoop a
                                    else do
                                        clearScreen
                                        let form = a !! (option -1)
                                        printInformation (content form)
                                        putStrLn " \nPresione Cualquier letra para continuar"
                                        getChar
                                        mainLoop a
                            else if option == "3"
                                then do
                                    clearScreen 
                                    let form = mostResponse (tail a) (head a)
                                    putStrLn ("Formulario Más votado '" ++ (name form)++"'")
                                    putStrLn " \nPresione Cualquier letra para continuar"
                                    getChar
                                    mainLoop a
                                else mainLoop a

                else if  option == "4" 
                    then do
                        putStrLn "Adios!"
                        return ()
                    else mainLoop a

mostResponse :: [Form] ->Form-> Form
mostResponse [] most = most
mostResponse list most= do
    if (response most) < (response(head list)) 
        then mostResponse (tail list) (head list)
        else mostResponse (tail list) most

automaticForm :: Form -> IO Form
automaticForm form = do
    let questions = map (\n ->  ( Question (question n) (automaticAnswer (answerContent n)))) (content form)
    return (Form questions (name form) ((response form) +1))

automaticAnswer :: [Answer] -> [Answer]
automaticAnswer list = do
    let g = mkStdGen 42
    let val = (randomR (0,((length list)-1) ) g)
    let oldAnswer = list !!  (fst val)
    replaceAtIndex (fst val) (Answer (text oldAnswer) ((stat oldAnswer) +1)) list

printInformation :: [Question] -> IO()
printInformation [] = return()
printInformation list = do
    let aux = head list
    putStrLn( "\n"++question aux)
    printAnswerInfo (answerContent aux)
    printInformation (tail list)

printAnswerInfo :: [Answer] -> IO()
printAnswerInfo [] = return ()
printAnswerInfo list = do
    let aux = head list
    putStrLn( (text aux )++" Total: "++ show (stat aux))
    printAnswerInfo (tail list)

makeForm ::IO Form
makeForm = do
    putStrLn"\nNombre del Formulario"
    name<- getLine
    questions <- makeQuestion []
    let form = (Form questions name 0)
    return form

makeQuestion :: [Question] -> IO [Question]
makeQuestion questions = do 
    clearScreen
    putStrLn "Escriba la pregunta"
    name <- getLine

    putStrLn "\nTipo de pregunta"
    putStrLn "1) Personalizada"
    putStrLn "2) De escala"
    option <- getLine
    answers <- doAnswer option

    putStrLn "\nCrear otra pregunta [y=Sí,n=no] (por defecto y)"
    option <- getLine
    if option == "n"
        then do
            let question = (Question name answers)
            return (questions ++ [question])
        else do
            let question = (Question name answers)
            makeQuestion (questions ++ [question])

doAnswer :: String -> IO [Answer]
doAnswer "1" = do
    answers <- makeAnswer []
    return answers
doAnswer _ = do
    putStrLn "\nCargar escala por defecto [y=Sí,n=no] (por defecto y)"
    option <- getLine
    if option == "n"
        then do
            answers <- makeSacleAnswer [] 5
            return answers
        else return defaultAnswer

makeAnswer :: [Answer] -> IO [Answer]
makeAnswer answers = do 
    putStrLn "Respuesta: "
    name <- getLine
    let answer = (Answer name 0)
    putStrLn "\nAgregar Otra [y=Sí,n=no] (por defecto y)"
    option <- getLine
    if option == "n"
        then return (answers ++ [answer])
        else do
            result <- makeAnswer (answers ++ [answer])
            return result

makeSacleAnswer :: [Answer] -> Int -> IO [Answer]
makeSacleAnswer answers 0 = return answers 
makeSacleAnswer answers n = do
    putStrLn ("Respuesta para "++ show n)
    name <- getLine
    let answer = (Answer name 0)
    result <- makeSacleAnswer (answers ++ [answer]) (n-1)
    return result

showForms :: [Form] -> Int-> IO()
showForms [] _ = return()
showForms a n= do
    putStrLn(show n ++ ") "++name (head a))
    showForms (tail a) (n+1)

doForm :: Form -> IO Form
doForm form = do
    questions <- doQuestion (content form)
    return (Form questions (name form) ((response form) +1))

doQuestion :: [Question] -> IO [Question]
doQuestion [] = return []
doQuestion list = do
    clearScreen
    let tempQuestion = head list
    putStrLn( "\n"++question tempQuestion)
    printAnswers (answerContent tempQuestion) 1 
    inputjar <- readLn
    let option = (inputjar ::Int)
    content <- doQuestion (tail list)
    answers<-addStat (answerContent tempQuestion) option
    let newQuestion = (Question (question tempQuestion) answers)
    return ([newQuestion] ++ content) 


addStat :: [Answer] -> Int ->IO [Answer]
addStat list 1 = do
    let header = head list
    let newAnswer = (Answer (text header)  (stat header+1) )
    return ([newAnswer] ++ tail list)
addStat list n = do
    content <- addStat (tail list) (n-1)
    return ( [(head list)] ++ content )


printAnswers :: [Answer] ->Int -> IO()
printAnswers [] _ = return()
printAnswers a n =do
    putStrLn(show n ++ ") "++text (head a))
    printAnswers (tail a) (n+1)

printMenu :: IO()
printMenu = do
    clearScreen 
    putStrLn "-- Menu --"
    putStrLn "1) Crear Formulario"
    putStrLn "2) Responder Formulario"
    putStrLn "3) Estadisticas"
    putStrLn "4) Salir"

replaceAtIndex :: Int -> a -> [a] -> [a]
replaceAtIndex n item ls = a ++ (item:b) where (a, (_:b)) = splitAt n ls