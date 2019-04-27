const { exec } = require('child_process');
// lambda that used to compile C code
const Execute = () => {
	exec('gcc main.c && ./a.out', (err, stdout, stderr) => {
	  if (err) { return; }
	  console.log(`stdout: ${stdout}`);
	});
}
const fileSystem = require('fs'); // file system
// main func
const main = () => {
	// parsing argument from the command line
	if (process.argv.length < 3 || process.argv.length > 3) {	// wrong arguments
   		console.log("---> Usage: [path to ft_fun directory]. <---");
    	process.exit(-1);
	} else {
			var pathArgument = process.argv[2];	// second argument
	let fileContent = {}; let text = ""; let i; // init properties
	const existCFiles = fileSystem.readdirSync(pathArgument);

	existCFiles.forEach(file => { // lambda to looking through content
		let tmpCont = fileSystem.readFileSync(pathArgument + '/'+ file, 'utf8');
		fileContent[+tmpCont.split('//file')[1]] = tmpCont;
	})
	for (i = 1; i <= existCFiles.length; ++i)
		if (fileContent[i])
			text += fileContent[i] + '\n';
	fileSystem.writeFile("main.c", text, (err) => { Execute(); });
	}
}
main();
